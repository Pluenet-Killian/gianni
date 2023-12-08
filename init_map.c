/*
** EPITECH PROJECT, 2023
** INIT_MAP
** File description:
** init_map
*/
#include "sokoban.h"

static void cond_calcu(Map *map, int cols, int *max_cols)
{
    if (cols > map->dim.len_cols) {
        map->dim.len_cols = cols;
    }
    if (cols > *max_cols) {
            *max_cols = cols;
        }
}

void calculate_map_dimensions(Map *map)
{
    int cols = 0;
    int max_cols = 0;

    for (int i = 0; map->map_b[i] != '\0'; i++) {
        if (map->map_b[i] == '\n') {
            map->dim.l_rows++;
            cond_calcu(map, cols, &max_cols);
            cols = 0;
        } else
            cols++;
    }
    if (cols > 0) {
        map->dim.l_rows++;
        if (cols > max_cols)
            max_cols = cols;
    }
    map->dim.len_cols = max_cols;
}

void fill_map_2d(Map *map)
{
    int row = 0;
    int col = 0;
    int index = 0;

    map->map_2d = malloc(sizeof(char *) * map->dim.l_rows);
    for (int i = 0; i < map->dim.l_rows; i++)
        map->map_2d[i] = malloc(sizeof(char) * map->dim.len_cols);
    while (map->map_b[index] != '\0') {
        if (map->map_b[index] == '\n' || map->map_b[index + 1] == '\0') {
            map->map_2d[row][col] = '\0';
            row++;
            col = 0;
        } else {
            map->map_2d[row][col] = map->map_b[index];
            col++;
        }
        index++;
    }
}

void open_map(int argc, char **argv, Map *map)
{
    struct stat stab;
    char *buffer;
    int source_fd = open(argv[1], O_RDWR);
    int size = 0;

    if (stat(argv[1], &stab) == -1) {
        endwin();
        exit(84);
    }
    buffer = malloc(stab.st_size + 1);
    read(source_fd, buffer, stab.st_size);
    buffer[stab.st_size] = '\0';
    map->map_b = buffer;
    cond_open_map(map, stab.st_size, buffer);
}

void show_map_ncurses(Map *map)
{
    for (int i = 0; i < map->dim.l_rows; i++)
        mvprintw(i, 0, "%s", map->map_2d[i]);
    refresh();
}

static void init_curses(int argc, char **argv, Map *map)
{
    error_case_base(argc, argv);
    open_map(argc, argv, map);
    map->dim.l_rows = 0;
    calculate_map_dimensions(map);
    fill_map_2d(map);
    if (!is_valid_map(map)) {
        endwin();
        exit(84);
    }
    initscr();
    clear();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
}

static void reset_game(Map *map)
{
    for (int i = 0; i < map->dim.l_rows; i++)
        my_strcpy(map->map_2d[i], map->initial_map_2d[i]);
    find_p_position(map);
}

static void show_last_map(Map *map)
{
    clear();
    show_map_ncurses(map);
    refresh();
    endwin();
}

static void show_game(Map *map, int ch)
{
    bool gameWon = false;
    bool gameLost = false;

    while (1 && (!gameWon && !gameLost)) {
        ch = getch();
        clear();
        move_p(map, ch);
        show_map_ncurses(map);
        gameWon = check_win(map);
        gameLost = check_loss(map);
    }
    show_last_map(map);
    if (gameWon)
        exit(0);
    else if (gameLost)
        exit(1);
}

int init(int argc, char **argv, Map *map)
{
    int ch;

    init_curses(argc, argv, map);
    find_o_positions(map);
    show_map_ncurses(map);
    if (LINES < map->dim.l_rows || COLS < map->dim.len_cols)
        mvprintw(LINES / 2, (COLS / 2) - 20, "Enlarge the terminal");
    show_game(map, ch);
    return 0;
}
