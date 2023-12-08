/*
** EPITECH PROJECT, 2023
** BASIC_ERROR_CASE
** File description:
** basic_error_case
*/

#include "sokoban.h"

void help(int argc, char **argv)
{
    if (argc > 1 && argv[1][0] == '-' && argv[1][1] == 'h') {
        write(1, "USAGE\n", 7);
        write(1, "     ./my_sokoban map\n", 23);
        write(1, "DESCRIPTION\n", 13);
        write(1, "     map file representing the warehouse map", 44);
        write(1, ", containing '#' for walls,\n", 29);
        write(1, "         'P' for the player, 'X' for boxes and 'o'", 50);
        write(1, "for storage locations.\n", 24);
        exit(84);
    }
}

void error_case_base(int argc, char **argv)
{
    help(argc, argv);
    if (argc < 2)
        exit(84);
}
