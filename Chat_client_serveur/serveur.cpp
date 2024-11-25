#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <vector>
#include <fstream>

#define PORT 8080
#define MAX_CLIENTS 100
#define BUFFER_SIZE 1024

std::vector<int> clients(MAX_CLIENTS, 0);

void broadcastMessage(const std::string& message, int sender) {
    for (int client : clients) {
        if (client != 0 && client != sender) {
            send(client, message.c_str(), message.size(), 0);
        }
    }
}

void broadcastImage(const std::string& fileName, int sender) {
    for (int client : clients) {
        if (client != 0 && client != sender) {
            std::ifstream file(fileName, std::ios::binary);
            if (file) {
                char buffer[BUFFER_SIZE];
                while (file.read(buffer, sizeof(buffer)) || file.gcount() > 0) {
                    send(client, buffer, file.gcount(), 0);
                }
                file.close();
            }
        }
    }
}

int main() {
    int serverSock, clientSock;
    sockaddr_in serverAddr{}, clientAddr{};
    socklen_t addrLen = sizeof(clientAddr);

    serverSock = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSock == -1) {
        perror("Erreur lors de la creation du socket");
        return 1;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(serverSock, reinterpret_cast<sockaddr*>(&serverAddr), sizeof(serverAddr)) == -1) {
        perror("Erreur lors de la liaison");
        close(serverSock);
        return 1;
    }

    if (listen(serverSock, SOMAXCONN) == -1) {
        perror("Erreur lors de l'ecoute");
        close(serverSock);
        return 1;
    }

    std::cout << "Serveur en attente de connexions sur le port " << PORT << "...\n";

    fd_set readfds;

    while (true) {
        FD_ZERO(&readfds);
        FD_SET(serverSock, &readfds);
        int max_sd = serverSock;

        for (int client : clients) {
            if (client > 0) {
                FD_SET(client, &readfds);
            }
            if (client > max_sd) {
                max_sd = client;
            }
        }

        int activity = select(max_sd + 1, &readfds, nullptr, nullptr, nullptr);
        if (activity < 0) {
            perror("Erreur lors de select");
        }

        if (FD_ISSET(serverSock, &readfds)) {
            clientSock = accept(serverSock, reinterpret_cast<sockaddr*>(&clientAddr), &addrLen);
            if (clientSock == -1) {
                perror("Erreur lors de l'acceptation");
                continue;
            }

            std::cout << "Nouvelle connexion acceptee.\n";

            for (int& client : clients) {
                if (client == 0) {
                    client = clientSock;
                    std::cout << "Ajoute a la liste des clients.\n";
                    break;
                }
            }
        }

        for (int& client : clients) {
            if (client == 0) continue;

            if (FD_ISSET(client, &readfds)) {
                char buffer[BUFFER_SIZE];
                int bytesReceived = recv(client, buffer, sizeof(buffer) - 1, 0);

                if (bytesReceived <= 0) {
                    if (bytesReceived == 0) {
                        std::cout << "Client deconnecte.\n";
                    } else {
                        perror("Erreur lors de la reception");
                    }
                    close(client);
                    client = 0;
                } else {
                    buffer[bytesReceived] = '\0';
                    std::cout << "Message recu : " << buffer << "\n";

                    if (std::strcmp(buffer, "SEND_IMAGE") == 0) {
                        char imageFile[BUFFER_SIZE];
                        recv(client, imageFile, sizeof(imageFile) - 1, 0);
                        broadcastImage(imageFile, client);
                    } else {
                        broadcastMessage(buffer, client);
                    }
                }
            }
        }
    }

    close(serverSock);
    return 0;
}
