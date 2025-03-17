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
    } else if (strcmp(action, "accept") == 0) {
        return mgba_press_button(conn, MGBA_BUTTON_START, delay_ms) && mgba_press_button(conn, MGBA_BUTTON_A, delay_ms) && mgba_press_button(conn, MGBA_BUTTON_B, delay_ms) && mgba_press_button(conn, MGBA_BUTTON_B, delay_ms);
    } else if (strcmp(action, "attack1") == 0) {
        return mgba_press_button(conn, MGBA_BUTTON_A, delay_ms) && mgba_press_button(conn, MGBA_BUTTON_A, delay_ms);
    } else if (strcmp(action, "attack2") == 0) {
        return mgba_press_button(conn, MGBA_BUTTON_A, delay_ms) && mgba_press_button(conn, MGBA_BUTTON_RIGHT, delay_ms) && mgba_press_button(conn, MGBA_BUTTON_A, delay_ms);
    } else if (strcmp(action, "attack3") == 0) {
        return mgba_press_button(conn, MGBA_BUTTON_A, delay_ms) && mgba_press_button(conn, MGBA_BUTTON_DOWN, delay_ms) && mgba_press_button(conn, MGBA_BUTTON_A, delay_ms);
    } else if (strcmp(action, "attack4") == 0) {
        return mgba_press_button(conn, MGBA_BUTTON_A, delay_ms) && mgba_press_button(conn, MGBA_BUTTON_RIGHT, delay_ms) && mgba_press_button(conn, MGBA_BUTTON_RIGHT, delay_ms) && mgba_press_button(conn, MGBA_BUTTON_A, delay_ms);
    } else if (strcmp(action, "switchpokemon1") == 0) {
        return mgba_press_button(conn, MGBA_BUTTON_DOWN, delay_ms) && mgba_press_button(conn, MGBA_BUTTON_A, delay_ms) && mgba_press_button(conn, MGBA_BUTTON_RIGHT, delay_ms) && mgba_press_button(conn, MGBA_BUTTON_A, delay_ms) && mgba_press_button(conn, MGBA_BUTTON_A, delay_ms);
    } else if (strcmp(action, "switchpokemon2") == 0) {
        return mgba_press_button(conn, MGBA_BUTTON_DOWN, delay_ms) && mgba_press_button(conn, MGBA_BUTTON_A, delay_ms) && mgba_press_button(conn, MGBA_BUTTON_RIGHT, delay_ms) && mgba_press_button(conn, MGBA_BUTTON_DOWN, delay_ms) && mgba_press_button(conn, MGBA_BUTTON_A, delay_ms) && mgba_press_button(conn, MGBA_BUTTON_A, delay_ms);
    } else if (strcmp(action, "switchpokemon3") == 0) {
        return mgba_press_button(conn, MGBA_BUTTON_DOWN, delay_ms) && mgba_press_button(conn, MGBA_BUTTON_A, delay_ms) && mgba_press_button(conn, MGBA_BUTTON_RIGHT, delay_ms) && mgba_press_button(conn, MGBA_BUTTON_DOWN, delay_ms) && mgba_press_button(conn, MGBA_BUTTON_DOWN, delay_ms) && mgba_press_button(conn, MGBA_BUTTON_A, delay_ms) && mgba_press_button(conn, MGBA_BUTTON_A, delay_ms);
    } else if (strcmp(action, "switchpokemon4") == 0) {
        return mgba_press_button(conn, MGBA_BUTTON_DOWN, delay_ms) && mgba_press_button(conn, MGBA_BUTTON_A, delay_ms) && mgba_press_button(conn, MGBA_BUTTON_RIGHT, delay_ms) && mgba_press_button(conn, MGBA_BUTTON_DOWN, delay_ms) && mgba_press_button(conn, MGBA_BUTTON_DOWN, delay_ms) && mgba_press_button(conn, MGBA_BUTTON_DOWN, delay_ms) && mgba_press_button(conn, MGBA_BUTTON_A, delay_ms) && mgba_press_button(conn, MGBA_BUTTON_A, delay_ms);
    } else if (strcmp(action, "switchpokemon5") == 0) {
        return mgba_press_button(conn, MGBA_BUTTON_DOWN, delay_ms) && mgba_press_button(conn, MGBA_BUTTON_A, delay_ms) && mgba_press_button(conn, MGBA_BUTTON_RIGHT, delay_ms) && mgba_press_button(conn, MGBA_BUTTON_DOWN, delay_ms) && mgba_press_button(conn, MGBA_BUTTON_DOWN, delay_ms) && mgba_press_button(conn, MGBA_BUTTON_DOWN, delay_ms) && mgba_press_button(conn, MGBA_BUTTON_DOWN, delay_ms) && mgba_press_button(conn, MGBA_BUTTON_A, delay_ms) && mgba_press_button(conn, MGBA_BUTTON_A, delay_ms);
    } else if (strcmp(action, "flee") == 0) {
        return mgba_press_button(conn, MGBA_BUTTON_RIGHT, delay_ms) && mgba_press_button(conn, MGBA_BUTTON_DOWN, delay_ms) && mgba_press_button(conn, MGBA_BUTTON_A, delay_ms);
    } else {
        return -1;
    }
}