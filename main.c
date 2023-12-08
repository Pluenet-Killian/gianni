/*
** EPITECH PROJECT, 2023
** MAIN
** File description:
** main
*/

#include "sokoban.h"

static void cond_cal(Map *map, int key, int result)
{
    if (key == KEY_LEFT)
        result = -1;
    else if (key == KEY_RIGHT)
        result = 1;
    else
        result = 0;
    map->n_c.behindX = (map->n_c.newX) + result;
    if (key == KEY_UP)
        result = -1;
    else if (key == KEY_DOWN)
        result = 1;
    else
        result = 0;
    map->n_c.behindY = (map->n_c.newY) + result;
}

void calculate_new_positions(Map *map, int key)
{
    int result = 0;

    map->n_c.newX = map->p_pos.pos_x;
    map->n_c.newY = map->p_pos.pos_y;
    switch (key) {
        case KEY_UP:
            (map->n_c.newY)--;
            break;
        case KEY_DOWN:
            (map->n_c.newY)++;
            break;
        case KEY_LEFT:
            (map->n_c.newX)--;
            break;
        case KEY_RIGHT:
            (map->n_c.newX)++;
            break;
    }
    cond_cal(map, key, result);
}

bool is_valid_move(Map *map, int x, int y)
{
    return x >= 0 && x < map->dim.len_cols && y >= 0 && y < map->dim.l_rows;
}

void handle_move(Map *map)
{
    char n_cell = map->map_2d[map->n_c.newY][map->n_c.newX];
    char b_c = is_valid_move(map, map->n_c.behindX, map->n_c.behindY) ?
        map->map_2d[map->n_c.behindY][map->n_c.behindX] : '#';
    bool isO = i_o_p(map, map->p_pos.pos_x, map->p_pos.pos_y);
    bool iXO = (n_cell == 'X') && i_o_p(map, map->n_c.newX, map->n_c.newY);
    bool isBehindXOnO = (b_c == 'O') && i_o_p(map,
        map->n_c.behindX, map->n_c.behindY);

    if (n_cell == 'X' && b_c != '#' && (b_c == ' ' || isBehindXOnO)) {
            map->map_2d[map->p_pos.pos_y][map->p_pos.pos_x] = isO ? 'O' : ' ';
            map->map_2d[map->n_c.behindY][map->n_c.behindX] = 'X';
            map->map_2d[map->n_c.newY][map->n_c.newX] = 'P';
            map->p_pos.pos_x = map->n_c.newX;
            map->p_pos.pos_y = map->n_c.newY;
        } else if ((n_cell == ' ' || n_cell == 'O') && !(iXO && b_c == '#')) {
            map->map_2d[map->p_pos.pos_y][map->p_pos.pos_x] = isO ? 'O' : ' ';
            map->p_pos.pos_x = map->n_c.newX;
            map->p_pos.pos_y = map->n_c.newY;
            map->map_2d[map->n_c.newY][map->n_c.newX] = 'P';
        }
}

void move_p(Map *map, int key)
{
    calculate_new_positions(map, key);
    if (is_valid_move(map, map->n_c.newX, map->n_c.newY)) {
        handle_move(map);
    }
}

int main(int argc, char **argv)
{
    Map *map = malloc(sizeof(Map));

    init_check(map);
    init(argc, argv, map);
}
