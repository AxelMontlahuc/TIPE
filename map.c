#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <winsock2.h>
#include <windows.h>

#pragma comment(lib, "ws2_32.lib")

typedef struct {
    int tile;
    char symbol;
} TileMapping;

void shift_string(const char *input, char *output, int x, int SIZE) {
    memcpy(output, input + x, SIZE - x);
    memcpy(output + (SIZE - x), input, x);
}

int request_offset(SOCKET sock, char* loc) {
    char* message = malloc(128 * sizeof(char));
    sprintf(message, "memoryDomain.read8,io,%s", loc);
    char server_reply[1024];
    int recv_size;
    if (send(sock, message, strlen(message), 0) < 0) {
        printf("Send failed. Error Code: %d\n", WSAGetLastError());
    }
    if ((recv_size = recv(sock, server_reply, sizeof(server_reply) - 1, 0)) == SOCKET_ERROR) {
        printf("Receive failed. Error Code: %d\n", WSAGetLastError());
    }
    server_reply[recv_size] = '\0';
    return atoi(server_reply);
}

char* request_range(SOCKET sock, char* address, char* length) {
    char* message = malloc(128 * sizeof(char));
    sprintf(message, "memoryDomain.readRange,vram,%s,%s", address, length);
    char* server_reply = malloc((32*32*16) * sizeof(char));
    int recv_size;
    if (send(sock, message, strlen(message), 0) < 0) {
        printf("Send failed. Error Code: %d\n", WSAGetLastError());
    }
    if ((recv_size = recv(sock, server_reply, 8192 - 1, 0)) == SOCKET_ERROR) {
        printf("Receive failed. Error Code: %d\n", WSAGetLastError());
    }
    server_reply[recv_size] = '\0';
    free(message);
    return server_reply;
}

char* latin1_to_hex(char* input, int length) {
    char* output = malloc((length * 2 + 1) * sizeof(char));
    for (int i = 0; i < length; i++) {
        sprintf(output + (i * 2), "%02x", (unsigned char)input[i]);
    }
    output[length * 2] = '\0';
    return output;
}

char* revert_offset(SOCKET sock, char* hex_offsetted, int length, int x_offset, int y_offset) {
    int tile_offset = (y_offset / 8) * 32 + (x_offset / 8);
    return hex_offsetted + (tile_offset * 4);
}

int** map_screen(SOCKET sock) {
    int x_offset = request_offset(sock, "0x4000018");
    int y_offset = request_offset(sock, "0x400001A");
    int tile_x_offset = x_offset / 8;
    int tile_y_offset = y_offset / 8;
    int** map = malloc(32 * sizeof(int*));
    for (int i = 0; i < 32; i++) {
        map[i] = malloc(32 * sizeof(int));
    }
    char* reply = request_range(sock, "0x0600e000", "2048");
    char* hex_reply = latin1_to_hex(reply, 2048);

    for (int row = 0; row < 32; row++) {
        for (int col = 0; col < 32; col++) {
            int src_row = (row + tile_y_offset) % 32;
            int src_col = (col + tile_x_offset) % 32;
            int tile_index = src_row * 32 + src_col;
            char buffer[5];
            strncpy(buffer, hex_reply + (tile_index * 4), 4);
            buffer[4] = '\0';
            int value = (int)strtol(buffer, NULL, 16);
            map[row][col] = value;
        }
    }
    free(reply);
    free(hex_reply);
    return map;
}

void free_map(int** map) {
    for (int i = 0; i < 32; i++) {
        free(map[i]);
    }
    free(map);
}

void show_map(SOCKET sock) {
    const char* possibleSymbols = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-_=+[]{};:'\",<>/?\\|`~";
    int symbolsCount = (int)strlen(possibleSymbols);
    int MAX_UNIQUE_TILES = symbolsCount;
    TileMapping dict[MAX_UNIQUE_TILES];
    int dictSize = 0;
    int** map = map_screen(sock);
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 30; j++) {
            int currentTile = map[i][j];
            char symbol = '?';
            if (currentTile == 0x0220 || currentTile == 0x0320) {
                symbol = '.';
            } else {
                int found = 0;
                for (int k = 0; k < dictSize; k++) {
                    if (dict[k].tile == currentTile) {
                        symbol = dict[k].symbol;
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    if (dictSize < symbolsCount && dictSize < MAX_UNIQUE_TILES) {
                        symbol = possibleSymbols[dictSize];
                        dict[dictSize].tile = currentTile;
                        dict[dictSize].symbol = symbol;
                        dictSize++;
                    }
                }
            }
            printf("%c ", symbol);
        }
        printf("\n");
    }
    free_map(map);
}

int main() {
    WSADATA wsa;
    SOCKET sock;
    struct sockaddr_in server;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("Winsock initialization failed. Error Code: %d\n", WSAGetLastError());
        return 1;
    }
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Socket creation failed. Error Code: %d\n", WSAGetLastError());
        return 1;
    }
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(8888);
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Connection failed. Error Code: %d\n", WSAGetLastError());
        return 1;
    }
    while (1) {
        system("@cls||clear");
        show_map(sock);
        Sleep(200);
    }
    closesocket(sock);
    WSACleanup();
    return 0;
}