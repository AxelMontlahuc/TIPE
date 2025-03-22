#include "../include/mgba_controller.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

int mgba_do_action(MGBAConnection* conn, const char* action, int delay_ms) {
    if (strcmp(action, "up") == 0) {
        return mgba_press_button(conn, MGBA_BUTTON_UP, delay_ms);
    } else if (strcmp(action, "down") == 0) {
        return mgba_press_button(conn, MGBA_BUTTON_DOWN, delay_ms);
    } else if (strcmp(action, "left") == 0) {
        return mgba_press_button(conn, MGBA_BUTTON_LEFT, delay_ms);
    } else if (strcmp(action, "right") == 0) {
        return mgba_press_button(conn, MGBA_BUTTON_RIGHT, delay_ms);
    } else if (strcmp(action, "a") == 0) {
        return mgba_press_button(conn, MGBA_BUTTON_A, delay_ms);
    } else if (strcmp(action, "b") == 0) {
        return mgba_press_button(conn, MGBA_BUTTON_B, delay_ms);
    } else if (strcmp(action, "start") == 0) {
        return mgba_press_button(conn, MGBA_BUTTON_START, delay_ms);
    } /*else if (strcmp(action, "select") == 0) {
        return mgba_press_button(conn, MGBA_BUTTON_SELECT, delay_ms);
    }*/ else {
        return -1;
    }
}