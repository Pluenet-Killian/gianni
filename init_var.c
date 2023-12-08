/*
** EPITECH PROJECT, 2023
** INIT_VAR
** File description:
** init_var
*/

#include "sokoban.h"

void init_check(Map *map)
{
    map->dim.l_rows = 0;
    map->dim.len_cols = 0;
    map->p_pos.pos_x = 0;
    map->p_pos.pos_y = 0;
    map->pos.pos_x = 0;
    map->pos.pos_y = 0;
    map->pos.next_x = 0;
    map->pos.next_y = 0;
    map->pos.next_next_x = 0;
    map->pos.next_next_y = 0;
    map->w.suc_o = 0;
    map->w.count_o = 0;
    map->w.los_x = 0;
    map->w.count_x = 0;
    map->w.count_p = 0;
    map->n_c.behindX = 0;
    map->n_c.behindY = 0;
    map->n_c.newX = 0;
    map->n_c.newX = 0;
}
