#include "../include/mgba_connection.h"
#include "../include/mgba_intel.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() {
    MGBAConnection conn;
    int result;
    
    // Connect to mGBA
    result = mgba_connect(&conn, "127.0.0.1", 8888);
    if (result != 0) {
        printf("Failed to connect to mGBA. Error code: %d\n", result);
        return 1;
    }
    
    printf("Connected to mGBA. Press Ctrl+C to exit.\n");
    
    int pokemon = 1;
    int max_hp = get_max_HP(conn.sock, pokemon);
    int hp = get_HP(conn.sock, pokemon);
    int level = get_level(conn.sock, pokemon);
    printf("Max HP: %d\n", max_hp);
    printf("HP: %d\n", hp);
    printf("Level: %d\n", level);
    
    // Clean up
    mgba_disconnect(&conn);
    return 0;
}