/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-yohann.mangenot
** File description:
** print_man
*/

#include "../include/my.h"

int print_man(void)
{
    struct stat sb;
    stat(ANTMAN_MAN, &sb);
    char *buff = malloc(sb.st_size + 1);
    int fd = open(ANTMAN_MAN, O_RDONLY);
    if (fd == -1)
        return (ERR_ANT_MAN);
    read(fd, buff, sb.st_size);
    write(1, buff, sb.st_size);
    close(fd);
    return (EXIT_SUCCESS);
}
