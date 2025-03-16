#include "../include/mgba_controller.h"
#include "../include/mgba_connection.h"
#include <stdio.h>
#include <stdlib.h>

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
    
    // Example movement pattern
    while (1) {
        mgba_press_button(&conn, MGBA_BUTTON_RIGHT, 50);
        mgba_press_button(&conn, MGBA_BUTTON_RIGHT, 50);
        mgba_press_button(&conn, MGBA_BUTTON_UP, 50);
        mgba_press_button(&conn, MGBA_BUTTON_UP, 50);
        mgba_press_button(&conn, MGBA_BUTTON_LEFT, 50);
        mgba_press_button(&conn, MGBA_BUTTON_LEFT, 50);
        mgba_press_button(&conn, MGBA_BUTTON_DOWN, 50);
        mgba_press_button(&conn, MGBA_BUTTON_DOWN, 50);
    }
    
    // Clean up
    mgba_disconnect(&conn);
    return 0;
}