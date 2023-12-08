/*
** EPITECH PROJECT, 2023
** CHECK_WIN_OR_LOSE
** File description:
** check_win_or_lose
*/

#include "sokoban.h"

bool check_win(Map *map)
{
    int x = 0;
    int y = 0;

    for (int i = 0; i < map->w.count_o; i++) {
        x = map->w.pos_o_x[i];
        y = map->w.pos_o_y[i];
        if (map->map_2d[y][x] != 'X')
            return false;
    }
    return true;
}

static bool is_blocked(Map *map, int x, int y)
{
    int blocked_sides = 0;

    if (x == 0 || map->map_2d[y][x - 1] == '#')
        blocked_sides += 1;
    if (x == map->dim.len_cols - 1 || map->map_2d[y][x + 1] == '#')
        blocked_sides += 1;
    if (y == 0 || map->map_2d[y - 1][x] == '#')
    blocked_sides++;
    if (y == map->dim.l_rows - 1 || map->map_2d[y + 1][x] == '#')
        blocked_sides += 1;
    return blocked_sides >= 2;
}

static int cond_check_lose(Map *map, int y)
{
    for (int x = 0; x < map->dim.len_cols; x++) {
        if (map->map_2d[y][x] == 'X' && !is_blocked(map, x, y)) {
            return 1;
        }
    }
    return 0;
}

bool check_loss(Map *map)
{
    int k = 0;

    for (int y = 0; y < map->dim.l_rows; y++) {
        k = cond_check_lose(map, y);
        if (k == 1)
            return false;
    }
    return true;
}
