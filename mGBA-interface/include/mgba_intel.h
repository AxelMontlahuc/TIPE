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

/**
 * @brief Gather the current ATK of a pokemon from the game VRAM
 */
int get_ATK(SOCKET sock, int pokemon);

/**
 * @brief Gather the current DEF of a pokemon from the game VRAM
 */
int get_DEF(SOCKET sock, int pokemon);

/**
 * @brief Gather the current SPEED of a pokemon from the game VRAM
 */
int get_SPEED(SOCKET sock, int pokemon);

/**
 * @brief Gather the current ATK_SPE of a pokemon from the game VRAM
 */
int get_ATK_SPE(SOCKET sock, int pokemon);

/**
 * @brief Gather the current DEF_SPE of a pokemon from the game VRAM
 */
int get_DEF_SPE(SOCKET sock, int pokemon);

/**
 * @brief Gather the PPs of the current pokemon from the game VRAM
 */
int get_PP(SOCKET sock, int move);

/**
 * @brief Gather the current enemy max HP from the game VRAM
 */
int get_enemy_max_HP(SOCKET sock);

/**
 * @brief Gather the current enemy HP from the game VRAM
 */
int get_enemy_HP(SOCKET sock);

/**
 * @brief Gather the current enemy level from the game VRAM
 */
int get_enemy_level(SOCKET sock);

/**
 * @brief Gather the zone the player is in from the game VRAM
 */
int get_zone(SOCKET sock);

#endif