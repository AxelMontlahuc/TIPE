#ifndef MGBA_CONNECTION_H
#define MGBA_CONNECTION_H

#include <winsock2.h>

/**
 * @brief Represents a connection to the mGBA emulator
 */
typedef struct {
    SOCKET sock;
    char ip_address[16];
    int port;
} MGBAConnection;

/**
 * @brief Initialize and connect to mGBA socket server
 * 
 * @param conn Pointer to MGBAConnection structure
 * @param ip_address IP address of mGBA server (typically "127.0.0.1")
 * @param port Port number of mGBA server (typically 8888)
 * @return int 0 on success, error code on failure
 */
int mgba_connect(MGBAConnection* conn, const char* ip_address, int port);

/**
 * @brief Send a command to mGBA and get the response
 * 
 * @param conn Pointer to MGBAConnection structure
 * @param message The command to send
 * @param response Buffer to store the response
 * @param response_size Size of the response buffer
 * @return int Number of bytes in the response, negative on error
 */
int mgba_send_command(MGBAConnection* conn, const char* message, char* response, int response_size);

/**
 * @brief Close the connection to mGBA
 * 
 * @param conn Pointer to MGBAConnection structure
 */
void mgba_disconnect(MGBAConnection* conn);

#endif /* MGBA_CONNECTION_H */