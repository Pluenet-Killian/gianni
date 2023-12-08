/*
** EPITECH PROJECT, 2023
** COND_INIT_MAP
** File description:
** cond_init_map
*/

#include "sokoban.h"


static bool is_valid_character(char c)
{
    return c == 'X' || c == 'O' || c == 'P' || c == '#' || c == ' ';
}

static bool is_valid_line(char *line)
{
    for (int x = 0; line[x] != '\0'; x++) {
        if (!is_valid_character(line[x])) {
            return false;
        }
    }
    return true;
}

bool is_valid_map(Map *map)
{
    for (int y = 0; y < map->dim.l_rows; y++) {
        if (!is_valid_line(map->map_2d[y])) {
            return false;
        }
    }
    return true;
}

void cond_open_map(Map *map, int size, char *buffer)
{
    if (size == 0) {
        endwin();
        free(buffer);
        exit(84);
    }
    find_p_position(map);
    if (map->w.count_x != map->w.count_o) {
        endwin();
        free(buffer);
        exit(84);
    }
}
