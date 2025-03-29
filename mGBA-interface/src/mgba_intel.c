#include "../include/mgba_intel.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

int get_max_HP(SOCKET sock, int pokemon) {
    char* address;
    switch (pokemon) {
        case 1:
            address = "0x02024544";
            break;
        case 2:
            address = "0x020245A8";
            break;
        case 3:
            address = "0x0202460C";
            break;
        case 4:
            address = "0x02024670";
            break;
        case 5:
            address = "0x020246D4";
            break;
        case 6:
            address = "0x02024738";
            break;
        default:
            return -1;
    }
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
    server_reply[recv_size] = '\0';
    free(message);
    return atoi(server_reply);
}

int get_HP(SOCKET sock, int pokemon) {
    char* address;
    switch (pokemon) {
        case 1:
            address = "0x02024542";
            break;
        case 2:
            address = "0x020245A6";
            break;
        case 3:
            address = "0x0202460A";
            break;
        case 4:
            address = "0x0202466E";
            break;
        case 5:
            address = "0x020246D2";
            break;
        case 6:
            address = "0x02024736";
            break;
        default:
            return -1;
    }
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
    server_reply[recv_size] = '\0';
    free(message);
    return atoi(server_reply);
}

int get_level(SOCKET sock, int pokemon) {
    char* address;
    switch (pokemon) {
        case 1:
            address = "0x02024540";
            break;
        case 2:
            address = "0x020245A4";
            break;
        case 3:
            address = "0x02024608";
            break;
        case 4:
            address = "0x0202466C";
            break;
        case 5:
            address = "0x020246D0";
            break;
        case 6:
            address = "0x02024734";
            break;
        default:
            return -1;
    }
    char* message = malloc(128 * sizeof(char));
    sprintf(message, "memoryDomain.read8,wram,%s", address);
    char* server_reply = malloc(64 * sizeof(char));
    int recv_size;
    if (send(sock, message, strlen(message), 0) < 0) {
        printf("Send failed. Error Code: %d\n", WSAGetLastError());
    }
    if ((recv_size = recv(sock, server_reply, 32 - 1, 0)) == SOCKET_ERROR) {
        printf("Receive failed. Error Code: %d\n", WSAGetLastError());
    }
    server_reply[recv_size] = '\0';
    free(message);
    return atoi(server_reply);
}

int get_ATK(SOCKET sock, int pokemon) {
    char* address;
    switch (pokemon) {
        case 1:
            address = "0x02024546";
            break;
        case 2:
            address = "0x020245AA";
            break;
        case 3:
            address = "0x0202460E";
            break;
        case 4:
            address = "0x02024672";
            break;
        case 5:
            address = "0x020246D6";
            break;
        case 6:
            address = "0x0202473A";
            break;
        default:
            return -1;
    }
    char* message = malloc(128 * sizeof(char));
    sprintf(message, "memoryDomain.read8,wram,%s", address);
    char* server_reply = malloc(64 * sizeof(char));
    int recv_size;
    if (send(sock, message, strlen(message), 0) < 0) {
        printf("Send failed. Error Code: %d\n", WSAGetLastError());
    }
    if ((recv_size = recv(sock, server_reply, 32 - 1, 0)) == SOCKET_ERROR) {
        printf("Receive failed. Error Code: %d\n", WSAGetLastError());
    }
    server_reply[recv_size] = '\0';
    free(message);
    return atoi(server_reply);
}

int get_DEF(SOCKET sock, int pokemon) {
    char* address;
    switch (pokemon) {
        case 1:
            address = "0x02024548";
            break;
        case 2:
            address = "0x020245AC";
            break;
        case 3:
            address = "0x02024610";
            break;
        case 4:
            address = "0x02024674";
            break;
        case 5:
            address = "0x020246D8";
            break;
        case 6:
            address = "0x0202473C";
            break;
        default:
            return -1;
    }
    char* message = malloc(128 * sizeof(char));
    sprintf(message, "memoryDomain.read8,wram,%s", address);
    char* server_reply = malloc(64 * sizeof(char));
    int recv_size;
    if (send(sock, message, strlen(message), 0) < 0) {
        printf("Send failed. Error Code: %d\n", WSAGetLastError());
    }
    if ((recv_size = recv(sock, server_reply, 32 - 1, 0)) == SOCKET_ERROR) {
        printf("Receive failed. Error Code: %d\n", WSAGetLastError());
    }
    server_reply[recv_size] = '\0';
    free(message);
    return atoi(server_reply);
}