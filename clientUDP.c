//
// Created by kour0 on 3/12/24.
//

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("Usage: %s <ip_address> <port>\n", argv[0]);
        return 1;
    }

    int clientSocket;
    struct sockaddr_in serverAddr;
    socklen_t addr_size;
    char message[1024];

    clientSocket = socket(PF_INET, SOCK_DGRAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(atoi(argv[2]));
    serverAddr.sin_addr.s_addr = inet_addr(argv[1]);
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

    addr_size = sizeof serverAddr;

    // Obtenir le temps actuel
    time_t tempsActuel;
    time(&tempsActuel);

    // Convertir en heure locale
    struct tm *heureLocale;
    heureLocale = localtime(&tempsActuel);

    // Send the hours, minutes and second to the server
    sprintf(message, "%02d:%02d:%02d", heureLocale->tm_hour, heureLocale->tm_min, heureLocale->tm_sec);

    sendto(clientSocket, message, strlen(message), 0, (struct sockaddr *) &serverAddr, addr_size);
    printf("[+]Data Send: %s\n", message);

    // Close the socket
    close(clientSocket);
    return 0;
}