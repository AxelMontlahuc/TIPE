#include "../include/mgba_controller.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

const char* BUTTON_NAMES[] = {
    "A", "B", "Select", "Start", "Right", "Left", "Up", "Down", "R", "L"
};

const char* mgba_button_to_string(MGBAButton button) {
    if (button >= MGBA_BUTTON_A && button <= MGBA_BUTTON_L) {
        return BUTTON_NAMES[button];
    }
    return "Unknown";
}

int mgba_press_button(MGBAConnection* conn, MGBAButton button, int delay_ms) {
    char message[64];
    char response[1024];
    const char* button_str = mgba_button_to_string(button);
    
    // Format the message
    snprintf(message, sizeof(message), "mgba-http.button.tap,%s", button_str);
    
    // Send the command
    int result = mgba_send_command(conn, message, response, sizeof(response));
    if (result < 0) {
        return result;
    }
    
    // Apply delay if requested
    if (delay_ms > 0) {
        Sleep(delay_ms);
    }
    
    return 0;
}

int mgba_hold_button(MGBAConnection* conn, MGBAButton button, int duration_frames) {
    char message[64];
    char response[1024];
    const char* button_str = mgba_button_to_string(button);
    
    // Format the message
    snprintf(message, sizeof(message), "mgba-http.button.hold,%s,%d", button_str, duration_frames);
    
    // Send the command
    int result = mgba_send_command(conn, message, response, sizeof(response));
    if (result < 0) {
        return result;
    }
    
    return 0;
}