/*
** EPITECH PROJECT, 2023
** SOKOBAN.H
** File description:
** sokoban.h
*/

#ifndef SOKOBAN_H_
    #define SOKOBAN_H_

    #include <curses.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <stdbool.h>

typedef struct {
    int l_rows;
    int len_cols;
} Dim_map;

typedef struct {
    int pos_x;
    int pos_y;
} P_pos;

typedef struct {
    int pos_x;
    int pos_y;
    int next_y;
    int next_x;
    int next_next_y;
    int next_next_x;
} Position;

typedef struct {
    WINDOW *win;
    int suc_o;
    int count_o;
    int los_x;
    int count_x;
    int count_p;
    int *pos_o_x;
    int *pos_o_y;
    bool pos_true;
} Window;

typedef struct {
    int row;
    int col;
    int *count;
} char_p_params;

typedef struct {
    int newX;
    int newY;
    int behindX;
    int behindY;
} new_coord;

typedef struct {
    char *map_b;
    char **map_2d;
    Dim_map dim;
    Position pos;
    Window w;
    P_pos p_pos;
    char **initial_map_2d;
    new_coord n_c;
} Map;


int init(int argc, char **argv, Map *map);
void error_case_base(int argc, char **argv);
void init_check(Map *map);
void move_p(Map *map, int key);
void find_p_position(Map *map);
void find_o_positions(Map *map);
bool i_o_p(Map *map, int x, int y);
char *my_strcpy(char *dest, char const *src);
void cond_open_map(Map *map, int size, char *buffer);
bool is_valid_map(Map *map);
bool check_win(Map *map);
bool check_loss(Map *map);

#endif
