#include "../include/mgba_connection.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

int mgba_connect(MGBAConnection* conn, const char* ip_address, int port) {
    WSADATA wsa;
    
    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        return WSAGetLastError();
    }
    
    // Create socket
    if ((conn->sock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        return WSAGetLastError();
    }
    
    // Prepare the sockaddr_in structure
    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr(ip_address);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    
    // Connect to server
    if (connect(conn->sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        return WSAGetLastError();
    }
    
    // Store connection details
    strncpy(conn->ip_address, ip_address, sizeof(conn->ip_address));
    conn->ip_address[sizeof(conn->ip_address) - 1] = '\0'; // Ensure null termination
    conn->port = port;
    
    return 0;
}

int mgba_send_command(MGBAConnection* conn, const char* message, char* response, int response_size) {
    int recv_size;
    
    // Send message
    if (send(conn->sock, message, strlen(message), 0) < 0) {
        return -WSAGetLastError();
    }
    
    // Receive response
    if ((recv_size = recv(conn->sock, response, response_size - 1, 0)) == SOCKET_ERROR) {
        return -WSAGetLastError();
    }
    
    // Null-terminate the response
    response[recv_size] = '\0';
    
    return recv_size;
}

void mgba_disconnect(MGBAConnection* conn) {
    closesocket(conn->sock);
    WSACleanup();
}