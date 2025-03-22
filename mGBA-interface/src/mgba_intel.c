#include "../include/mgba_intel.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

int get_max_HP(SOCKET sock, char* address, int pokemon) {
    char* message = malloc(128 * sizeof(char));
    sprintf(message, "memoryDomain.read16,wram,%s", address);
    char* server_reply = malloc(64 * sizeof(char));
    int recv_size;
    if (send(sock, message, strlen(message), 0) < 0) {
        printf("Send failed. Error Code: %d\n", WSAGetLastError());
    }
    if ((recv_size = recv(sock, server_reply, 32 - 1, 0)) == SOCKET_ERROR) {
        printf("Receive failed. Error Code: %d\n", WSAGetLastError());
    }
    printf("Server reply: %s\n", server_reply);
    server_reply[recv_size] = '\0';
    free(message);
    printf("Server reply: %s\n", server_reply);
    return atoi(server_reply);
}