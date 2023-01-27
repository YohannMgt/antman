/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-yohann.mangenot
** File description:
** antman
*/

#include "include/my.h"

char *extract_file(char *path)
{
    struct stat sb;
    int fd = open(path, O_RDONLY);
    if (fd == -1)
        return (NULL);
    stat(path, &sb);
    char *file = malloc(sb.st_size + 1);
    if (read(fd, file, sb.st_size) == -1)
        return (NULL);
    close(fd);
    return (file);
}

int chose_algorithm(char *file, int file_type, int size)
{
    switch (file_type) {
        case LYR:
            return (decompress_txt(file));
        case HTML:
            return (decompress_txt(file));
        case PPM:
            return (decompress_ppm(file, size));
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
    if (sb.st_size == 0)
        return (EXIT_SUCCESS);
    if ((sb.st_mode & S_IFMT) != S_IFREG)
        return (error_manager(ERR_FOLD, ""));
    char *file = extract_file(av[ac - 2]);
    if (file == NULL)
        return (error_manager(ERR_FILE, av[ac - 2]));
    int file_type = my_getnbr(av[ac - 1]);
    if (file_type < 1 || file_type > 3)
        return (error_manager(ERR_TYPE, ""));
    return (launch_algo(file, file_type, file_size(av[ac - 2])));
}
