/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-yohann.mangenot
** File description:
** antman
*/

#include "include/my.h"

int find_file_type(char *path)
{
    int i;
    for (i = my_strlen(path); path[i] != '.'; i--)
        ;
    while (i < my_strlen(path))
        switch (path[i]) {
            case 't':
                return (LYR);
            case 'l':
                return (LYR);
            case 'h':
                return (HTML);
            case 'p':
                return (PPM);
            case '.':
                i++;
                break;
            default: return (EXIT_SUCCESS);
        }
    return (EXIT_SUCCESS);
}

char *extract_file(char *path)
{
    int fd = open(path, O_RDONLY);
    if (fd == -1)
        return (NULL);
    int size = file_size(path);
    char *file = malloc(NOT_ZERO(size) + 1);
    if (read(fd, file, size) == -1)
        return (NULL);
    close(fd);
    return (file);
}

int chose_algorithm(char *file, int file_type, int size)
{
    switch (file_type) {
        case LYR:
            return (compress_txt(file));
        case HTML:
            return (compress_txt(file));
        case PPM:
            return (compress_ppm(file, size));
        default:
            return (EXIT_FAILURE);
    }
}

int launch_algo(char *file, int file_type, int size)
{
    switch (chose_algorithm(file, file_type, size)) {
        case 84: return (error_manager(ERR_EXEC, ""));
        case EXIT_FAILURE: return (error_manager(ERR_ALGO, ""));
    }
    return (EXIT_SUCCESS);
}

int main(int ac, char **av)
{
    if (ac >= 2 && av[1][0] == '-' && av[1][1] == 'h')
        return (error_manager(print_man(), ""));
    if (ac != 3)
        return (error_manager(ERR_ARGS, ""));
    struct stat sb;
    if (stat(av[1], &sb) == -1)
        return (84);
    if ((sb.st_mode & S_IFMT) != S_IFREG)
        return (error_manager(ERR_FOLD, ""));
    if (sb.st_size == 0)
        return (0);
    char *file = extract_file(av[1]);
    if (file == NULL)
        return (error_manager(ERR_FILE, av[1]));
    int file_type = find_file_type(av[1]);
    if (file_type != my_getnbr(av[2]))
        return (error_manager(ERR_TYPE, ""));
    return (launch_algo(file, file_type, file_size(av[1])));
}
