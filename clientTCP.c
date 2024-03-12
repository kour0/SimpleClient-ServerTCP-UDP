//
// Created by kour0 on 3/5/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {

    if (argc != 3) {
        printf("Usage: %s <ip> <port>\n", argv[0]);
        return 1;
    }

    int sock;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    struct sockaddr_in serv_addr;

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons((ushort) atoi(argv[2]));
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

    // Convertir les adresses IPv4 et IPv6 de texte en binaire
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    // On affiche le message de connexion
    char buffer[1024] = {0};
    int valread = read(sock, buffer, 1024);
    printf("%s\n", buffer);

    // On débute la communication, on fait deux processus, un pour lire et un pour écrire
    if (fork() == 0) {
        while (1) {
            // On lit le message
            read(sock, buffer, 1024);
            printf("Message reçu du Client: %s", buffer);
            // On vide le buffer
            memset(buffer, 0, 1024);
            // Si la connexion est fermée, on arrête le processus
            if (strcmp(buffer, "Connection closed") == 0) {
                break;
            }
        }
    } else {
        while (1) {
            // On écrit le message
            fgets(buffer, 1024, stdin);
            send(sock, buffer, strlen(buffer), 0);
            // On vide le buffer
            memset(buffer, 0, 1024);
        }
    }
}