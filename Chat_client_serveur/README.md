# Chat Client avec Interface en Temps Réel

## Description

Ce projet implémente un **client de chat en temps réel** en utilisant les sockets en C++ et l'interface graphique en terminal avec la bibliothèque **ncurses**. Le client se connecte à un serveur (qui doit être exécuté séparément) pour envoyer et recevoir des messages.

### Fonctionnalités principales :
- Interface graphique en temps réel qui affiche les messages entrants et sortants.
- Envoi de messages textuels.
- Chaque message est affiché avec une couleur différente pour l'utilisateur et les autres utilisateurs.
- Utilisation de threads pour recevoir des messages sans bloquer l'interface utilisateur.
- Possibilité de saisir des messages via un terminal interactif.

## Prérequis

Avant de commencer, assurez-vous d'avoir installé les bibliothèques nécessaires sur votre machine :

- **C++ compiler (g++)**
- **ncurses library** (utilisé pour l'interface graphique en terminal)
- **pthread library** (pour la gestion des threads)

Sur un système basé sur Debian/Ubuntu, vous pouvez installer `ncurses` et `pthread` avec la commande suivante :
```bash
sudo apt-get install libncurses5-dev libpthread-stubs0-dev
```

## Compilation

Pour compiler le projet, utilisez la commande suivante dans le terminal :

```bash
g++ -o chat_client chat_client.cpp -lncurses -pthread
```

Cette commande compile le fichier `chat_client.cpp` et génère un exécutable appelé `chat_client`.

## Exécution

1. **Lancer le serveur** : Avant d'exécuter le client, vous devez avoir un serveur qui écoute sur le même port. Si vous n'avez pas encore le serveur, il vous faudra en implémenter un (en C/C++ ou une autre technologie) qui accepte les connexions sur le port **8080**.

2. **Lancer le client** : Après avoir compilé le programme, vous pouvez exécuter le client avec la commande suivante :

```bash
./chat_client
```

3. **Interface utilisateur** : Lorsque vous lancez le client, vous serez invité à entrer votre nom. Ensuite, vous pourrez commencer à envoyer des messages. Les messages envoyés seront visibles par vous et par les autres utilisateurs connectés.

## Commandes et Interaction

- **Saisie de message** : Tapez un message dans le champ de texte en bas de l'écran et appuyez sur "Entrée" pour l'envoyer.
- **Suppression de texte** : Utilisez la touche `Backspace` pour supprimer le dernier caractère saisi.
- **Messages entrants** : Les messages reçus des autres utilisateurs sont affichés dans la fenêtre principale.

## Fonctionnalités futures

- Ajout de la possibilité d'envoyer des fichiers ou des images.
- Amélioration de la gestion des utilisateurs (pseudo unique, gestion des connexions/déconnexions).
- Ajout de commandes supplémentaires pour gérer des salons de discussion.

## Auteurs

- **Rojo** 

### Explication des sections :
1. **Description** : Une vue d'ensemble du programme, ce qu'il fait et ses principales fonctionnalités.
2. **Prérequis** : Les bibliothèques nécessaires pour faire fonctionner le programme, y compris les instructions d'installation pour `ncurses` et `pthread`.
3. **Compilation** : Indications pour compiler le projet en utilisant `g++`.
4. **Exécution** : Comment exécuter le client et se connecter à un serveur.
5. **Commandes et Interaction** : Comment interagir avec l'interface graphique en ligne de commande.
6. **Fonctionnalités futures** : Les améliorations possibles et les fonctionnalités qui pourraient être ajoutées dans le futur.
7. **Auteurs** : Une mention de l'auteur du projet.
8. **Licence** : Information de licence pour le projet.

### Comment l'utiliser :
1. Installez les bibliothèques nécessaires et compilez le programme.
2. Assurez-vous que le serveur est en cours d'exécution sur le port 8080.
3. Lancez le client et commencez à discuter avec les autres utilisateurs connectés.