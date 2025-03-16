#ifndef MGBA_CONTROLLER_H
#define MGBA_CONTROLLER_H

#include "mgba_connection.h"

/**
 * @brief Available buttons to press in mGBA
 */
typedef enum {
    MGBA_BUTTON_A,
    MGBA_BUTTON_B,
    MGBA_BUTTON_SELECT,
    MGBA_BUTTON_START,
    MGBA_BUTTON_RIGHT,
    MGBA_BUTTON_LEFT,
    MGBA_BUTTON_UP,
    MGBA_BUTTON_DOWN,
    MGBA_BUTTON_R,
    MGBA_BUTTON_L
} MGBAButton;

/**
 * @brief Press a button once
 * 
 * @param conn Pointer to MGBAConnection structure
 * @param button Button to press
 * @param delay_ms Delay after button press in milliseconds
 * @return int 0 on success, error code on failure
 */
int mgba_press_button(MGBAConnection* conn, MGBAButton button, int delay_ms);

/**
 * @brief Hold a button for specified duration
 * 
 * @param conn Pointer to MGBAConnection structure
 * @param button Button to hold
 * @param duration_frames Duration to hold the button in frames
 * @return int 0 on success, error code on failure
 */
int mgba_hold_button(MGBAConnection* conn, MGBAButton button, int duration_frames);

/**
 * @brief Convert button enum to string representation
 * 
 * @param button Button enum value
 * @return const char* String representation of button
 */
const char* mgba_button_to_string(MGBAButton button);

#endif /* MGBA_CONTROLLER_H */