#ifndef MGBA_INTEL_H
#define MGBA_INTEL_H

#include "mgba_connection.h"

/**
 * @brief Gather the maximum HP of a pokemon from the game VRAM
 */
int get_max_HP(SOCKET sock, char* address, int pokemon);

#endif