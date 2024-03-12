//
// Created by kour0 on 3/5/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080
#define SOMAXCONN 3

int main() {
    int serverSocket, dialogSocket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "bonjour";

    // Création du socket
    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Attacher le socket à l'adresse et au port spécifié
    if (bind(serverSocket, (struct sockaddr *) &address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Ecoute du socket
    if (listen(serverSocket, SOMAXCONN) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Accepter la connexion entrante
    dialogSocket = accept(serverSocket, (struct sockaddr *) &address, (socklen_t *) &addrlen);

    if (dialogSocket < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    } else {
        printf("Connection accepted\n");
    }

    // On envoie le bonjour
    send(dialogSocket, hello, strlen(hello), 0);
    printf("Hello message sent\n");

    // On fait deux processus pour le dialogue, un pour la lecture et un pour l'écriture
    if (fork() == 0) {
        while (1) {
            // On lit le message
            read(dialogSocket, buffer, 1024);
            printf("Message reçu du Client: %s", buffer);
            // On vide le buffer
            memset(buffer, 0, 1024);
        }
    } else {
        while (1) {
            // On écrit le message
            fgets(buffer, 1024, stdin);
            send(dialogSocket, buffer, strlen(buffer), 0);
            // On vide le buffer
            memset(buffer, 0, 1024);
        }
    }
}

