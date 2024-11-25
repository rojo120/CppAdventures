#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <ncurses.h>
#include <vector>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_MESSAGES 20

int sock;
std::vector<std::string> messages;
char input_buffer[BUFFER_SIZE];
std::string client_name;

WINDOW *message_win;
WINDOW *input_win;

void* receive_messages(void* arg) {
    char buffer[BUFFER_SIZE];
    while (true) {
        int bytesReceived = recv(sock, buffer, sizeof(buffer) - 1, 0);
        if (bytesReceived > 0) {
            buffer[bytesReceived] = '\0';
            if (messages.size() < MAX_MESSAGES) {
                messages.push_back(std::string(buffer));
            } else {
                messages.erase(messages.begin());
                messages.push_back(std::string(buffer));
            }

            werase(message_win);
            box(message_win, 0, 0);
            mvwprintw(message_win, 0, 2, "Messages");

            for (size_t i = 0; i < messages.size(); i++) {
                if (messages[i].find(client_name + ":") == 0) {
                    // Afficher le message de l'utilisateur avec un encadré bleu
                    wattron(message_win, COLOR_PAIR(1));  // Couleur bleue pour le message de l'utilisateur
                    mvwprintw(message_win, i + 1, COLS - messages[i].length() - 2, "%s", messages[i].c_str());
                    wattroff(message_win, COLOR_PAIR(1));
                } else {
                    // Afficher le message des autres avec un encadré blanc
                    wattron(message_win, COLOR_PAIR(2));  // Couleur blanche pour les messages des autres
                    mvwprintw(message_win, i + 1, 2, "%s", messages[i].c_str());
                    wattroff(message_win, COLOR_PAIR(2));
                }
            }
            wrefresh(message_win);
        }
    }
}

int main() {
    struct sockaddr_in serverAddr;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Echec de la creation du socket");
        return 1;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Echec de la connexion");
        close(sock);
        return 1;
    }

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    // Initialisation des couleurs
    start_color();
    init_pair(1, COLOR_BLUE, COLOR_BLACK);  // Paire de couleur pour les messages de l'utilisateur
    init_pair(2, COLOR_WHITE, COLOR_BLACK);  // Paire de couleur pour les messages des autres

    int height = LINES - 3;
    int width = COLS;
    
    message_win = newwin(height, width, 0, 0);
    box(message_win, 0, 0);
    mvwprintw(message_win, 0, 2, "Messages");
    wrefresh(message_win);

    input_win = newwin(3, width, height, 0);
    box(input_win, 0, 0);
    mvwprintw(input_win, 1, 2, "> ");
    wrefresh(input_win);

    mvwprintw(input_win, 1, 2, "Entrez votre nom: ");
    wrefresh(input_win);
    wgetstr(input_win, input_buffer);
    client_name = input_buffer;
    werase(input_win);
    box(input_win, 0, 0);
    mvwprintw(input_win, 1, 2, "> ");
    wrefresh(input_win);

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, receive_messages, NULL);

    int ch;
    int input_len = 0;
    while (true) {
        ch = getch();
        if (ch == 10) {  // Si l'utilisateur appuie sur "Entrée"
            std::string message = client_name + ": " + input_buffer;

            if (messages.size() < MAX_MESSAGES) {
                messages.push_back(message);
            } else {
                messages.erase(messages.begin());
                messages.push_back(message);
            }

            werase(message_win);
            box(message_win, 0, 0);
            mvwprintw(message_win, 0, 2, "Messages");

            for (size_t i = 0; i < messages.size(); i++) {
                if (messages[i].find(client_name + ":") == 0) {
                    wattron(message_win, COLOR_PAIR(1));  // Couleur bleue pour le message de l'utilisateur
                    mvwprintw(message_win, i + 1, COLS - messages[i].length() - 2, "%s", messages[i].c_str());
                    wattroff(message_win, COLOR_PAIR(1));
                } else {
                    wattron(message_win, COLOR_PAIR(2));  // Couleur blanche pour les messages des autres
                    mvwprintw(message_win, i + 1, 2, "%s", messages[i].c_str());
                    wattroff(message_win, COLOR_PAIR(2));
                }
            }
            wrefresh(message_win);

            send(sock, message.c_str(), message.length(), 0);

            memset(input_buffer, 0, sizeof(input_buffer));
            input_len = 0;

            werase(input_win);
            box(input_win, 0, 0);
            mvwprintw(input_win, 1, 2, "> ");
            wrefresh(input_win);
        } else if (ch == KEY_BACKSPACE || ch == 127) {  // Gestion de la touche "Backspace"
            if (input_len > 0) {
                input_buffer[--input_len] = '\0';
            }
        } else if (ch >= 32 && ch <= 126 && input_len < BUFFER_SIZE - 1) {  // Ajout d'un caractère
            input_buffer[input_len++] = ch;
            input_buffer[input_len] = '\0';
        }

        // Afficher l'entrée utilisateur en temps réel
        werase(input_win);
        box(input_win, 0, 0);
        mvwprintw(input_win, 1, 2, "> %s", input_buffer);  // Affichage du texte en cours de saisie
        wrefresh(input_win);
    }

    close(sock);
    endwin();
    return 0;
}
