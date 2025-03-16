#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <winsock2.h>
#include <windows.h>

#pragma comment(lib, "ws2_32.lib")

void press_key(char* input, SOCKET sock) {
  char* message = malloc(128 * sizeof(char));
  sprintf(message, "mgba-http.button.tap,%s", input);
  printf("Message: %s\n", message);
  char server_reply[1024];
  int recv_size;
  if (send(sock, message, strlen(message), 0) < 0) {
    printf("Send failed. Error Code: %d\n", WSAGetLastError());
  }

  if ((recv_size = recv(sock, server_reply, sizeof(server_reply) - 1, 0)) == SOCKET_ERROR) {
      printf("Receive failed. Error Code: %d\n", WSAGetLastError());
  }

  server_reply[recv_size] = '\0';
  printf("Server reply: %s\n", server_reply);
  Sleep(50);
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
      press_key("Right", sock);
      press_key("Right", sock);
      press_key("Right", sock);
      press_key("Right", sock);
      press_key("Up", sock);
      press_key("Up", sock);
      press_key("Up", sock);
      press_key("Up", sock);
      press_key("Left", sock);
      press_key("Left", sock);
      press_key("Left", sock);
      press_key("Left", sock);
      press_key("Down", sock);
      press_key("Down", sock);
      press_key("Down", sock);
      press_key("Down", sock);
    }

    closesocket(sock);
    WSACleanup();

    return 0;
}