#ifndef MGBA_MAP_H
#define MGBA_MAP_H

#include "mgba_connection.h"

/**
 * @brief Represents a map tile with ID and display symbol
 */
typedef struct {
    int tile_id;
    char symbol;
} MGBATileMapping;

/**
 * @brief Represents a game map with dimensions and tile data
 */
typedef struct {
    int width;
    int height;
    int** tiles;
} MGBAMap;

/**
 * @brief Read the current map tiles from the screen
 * 
 * @param conn Pointer to MGBAConnection structure
 * @return MGBAMap* Pointer to newly allocated map structure (must be freed with mgba_free_map)
 */
MGBAMap* mgba_read_map(MGBAConnection* conn);

/**
 * @brief Free the memory allocated for a map
 * 
 * @param map Pointer to MGBAMap structure
 */
void mgba_free_map(MGBAMap* map);

/**
 * @brief Read the current screen offset (scroll position)
 * 
 * @param conn Pointer to MGBAConnection structure
 * @param x_offset Pointer to store x offset
 * @param y_offset Pointer to store y offset
 * @return int 0 on success, error code on failure
 */
int mgba_get_screen_offset(MGBAConnection* conn, int* x_offset, int* y_offset);

/**
 * @brief Format map as ASCII symbols for display
 * 
 * @param map Pointer to MGBAMap structure
 * @param output Buffer to store ASCII representation
 * @param output_size Size of output buffer
 * @return int 0 on success, error code on failure
 */
int mgba_map_to_ascii(MGBAMap* map, char* output, int output_size);

/**
 * @brief Print the current map to console
 * 
 * @param conn Pointer to MGBAConnection structure
 * @return int 0 on success, error code on failure
 */
int mgba_print_map(MGBAConnection* conn);

#endif /* MGBA_MAP_H */