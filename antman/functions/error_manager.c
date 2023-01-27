/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-yohann.mangenot
** File description:
** error_manager
*/

#include "../include/my.h"

char *make_error_message(char *path)
{
    char *message = malloc((my_strlen(path) + 55) * sizeof(char));
    my_strcpy(message, "antman: cannot access '");
    my_strcat(message, path);
    my_strcat(message, "': No such file or directory\n");
    return (message);
}

int error_manager_bis(int error_code)
{
    switch (error_code) {
        case ERR_ANT_MAN:
            write(2, ERR_ANT_MAN_MSG, my_strlen(ERR_ANT_MAN_MSG));
            return (84);
        case ERR_ALGO:
            write(2, ERR_ALGO_MSG, my_strlen(ERR_ALGO_MSG));
            return (84);
        case ERR_FOLD:
            write(2, ERR_FOLD_MSG, my_strlen(ERR_FOLD_MSG));
            return (84);
        case ERR_STAT:
            write(2, ERR_STAT_MSG, my_strlen(ERR_STAT_MSG));
            return (84);
    }
    return (0);
}

int error_manager(int error_code, char *path)
{
    switch (error_code) {
        case NO_ERROR:
            return (EXIT_SUCCESS);
        case ERR_ARGS:
            write(2, ERR_ARGS_MSG, my_strlen(ERR_ARGS_MSG));
            return (84);
        case ERR_TYPE:
            write(2, ERR_TYPE_MSG, my_strlen(ERR_TYPE_MSG));
            return (84);
        case ERR_FILE:
            write(2, make_error_message(path), 55 + my_strlen(path));
            return (84);
        case ERR_EXEC:
            write(2, ERR_EXEC_MSG, my_strlen(ERR_EXEC_MSG));
            return (84);
    }
    return (error_manager_bis(error_code));
}
