/*
** EPITECH PROJECT, 2023
** FIND_POSITION
** File description:
** find_position
*/

#include "sokoban.h"

static void process_character(Map *map, char character, char_p_params *params)
{
    if (character == 'O') {
        map->w.pos_o_x[*(params->count)] = params->col;
        map->w.pos_o_y[*(params->count)] = params->row;
        (*(params->count))++;
    }
}

static void cond_find_o(Map *map, int count)
{
    char_p_params params = {0, 0, &count};

    for (int i = 0; map->map_b[i] != '\0'; i++) {
        if (map->map_b[i] == '\n') {
            params.row++;
            params.col = 0;
        } else {
            process_character(map, map->map_b[i], &params);
            params.col++;
        }
    }
}

void find_o_positions(Map *map)
{
    int count = 0;

    for (int i = 0; map->map_b[i] != '\0'; i++) {
        if (map->map_b[i] == 'O')
            count++;
    }
    map->w.pos_o_x = malloc(sizeof(int) * count);
    map->w.pos_o_y = malloc(sizeof(int) * count);
    map->w.count_o = count;
    count = 0;
    cond_find_o(map, count);
}

void find_p_position(Map *map)
{
    int index = 0;
    int row = 0;
    int col = 0;

    for (int i = 0; map->map_b[i] != '\0'; i++) {
        if (map->map_b[i] == 'P') {
            map->p_pos.pos_x = col;
            map->p_pos.pos_y = row;
            return;
        }
        if (map->map_b[i] == '\n') {
            row++;
            col = 0;
        } else
            col++;
    }
}

bool i_o_p(Map *map, int x, int y)
{
    for (int i = 0; i < map->w.count_o; i++) {
        if (map->w.pos_o_x[i] == x && map->w.pos_o_y[i] == y)
            return true;
    }
    return false;
}
