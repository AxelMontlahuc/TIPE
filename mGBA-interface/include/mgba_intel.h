#ifndef MGBA_INTEL_H
#define MGBA_INTEL_H

#include "mgba_connection.h"

/**
 * @brief Gather the maximum HP of a pokemon from the game VRAM
 */
int get_max_HP(SOCKET sock, int pokemon);

/**
 * @brief Gather the current HP of a pokemon from the game VRAM
 */
int get_HP(SOCKET sock, int pokemon);

/**
 * @brief Gather the current level of a pokemon from the game VRAM
 */
int get_level(SOCKET sock, int pokemon);

#endif