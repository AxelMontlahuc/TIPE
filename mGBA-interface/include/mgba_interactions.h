#ifndef MGBA_INTERACTIONS_H
#define MGBA_INTERACTIONS_H

#include "mgba_connection.h"

/**
 * @brief Perform a game action by executing a sequence of button presses
 * 
 * @param conn Pointer to MGBAConnection structure
 * @param action String describing the action to perform (e.g., "up", "attack1", "switchpokemon1")
 * @param delay_ms Delay between button presses in milliseconds
 * @return int 0 on success, -1 if action is not recognized, error code on failure
 */
int mgba_do_action(MGBAConnection* conn, const char* action, int delay_ms);

#endif /* MGBA_INTERACTIONS_H */