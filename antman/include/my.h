/*
** EPITECH PROJECT, 2022
** B-CPE-101-LYN-1-1-BSQ-mael.rabot
** File description:
** my.h
*/

#ifndef TEK1_MY_H_
    #define TEK1_MY_H_

    #define MIN(x, y)           (((x) < (y)) ? (x) : (y))
    #define MAX(x, y)           (((x) > (y)) ? (x) : (y))
    #define ABS(x)              ((x) > 0) ? (x) : (-x)
    #define RAD_TO_DEGRES(x)    (x) * (180 / PI)
    #define UP(x)               ((x) < 0) ? 0 : (x)
    #define NOT_ZERO(x)         ((x) <= 0) ? 1 : (x)

    #define PI                  3.14159

    #define MALLOC_SIZE         32
    #define MAX_CHAR            500
    #define CHAR_SIZE           6
    #define CHAR_OFFSET         35
    #define NO_CODE             -84
    #define PPM_METADATA        3

    #define LYR                 1
    #define HTML                2
    #define PPM                 3

    #define NO_ERROR            0
    #define ERR_ARGS            1
    #define ERR_TYPE            2
    #define ERR_FILE            3
    #define ERR_EXEC            4
    #define ERR_ALGO            5
    #define ERR_ANT_MAN         6
    #define ERR_FOLD            7
    #define ERR_STAT            8

    #define HELP                ", use -h to display help\n"
    #define ERR_ARGS_MSG        "Bad argument number"HELP
    #define ERR_TYPE_MSG        "Bad file type"HELP
    #define ERR_EXEC_MSG        "Compression error\n"
    #define ERR_ALGO_MSG        "Couldn't find an algorithm for this file"HELP
    #define ERR_ANT_MAN_MSG     ANTMAN_MAN" does not exist\n"
    #define ERR_FOLD_MSG        "Cannot open a folder"HELP
    #define ERR_STAT_MSG        "File can't be read"HELP

    #define ANTMAN_MAN          "antman_man.txt"

    #include "mylib.h"
    #include "my_printf.h"
    #include "my_structs.h"

    #include <math.h>
    #include <stdarg.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stddef.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <sys/syscall.h>
    #include <fcntl.h>
    #include <dirent.h>
    #include <stdint.h>
    #include <time.h>
    #include <sys/sysmacros.h>
    #include <pwd.h>
    #include <grp.h>
    #include <errno.h>
    #include <string.h>

    void insertion_sort(node_t **list, int size);
    void display_tree(node_t *node, int level);
    void free_ppm(ppm_t *ppm, dict_t *dict);

    int compress_txt(char *file);
    int *find_frequency(char *file);
    int count_item(int *list);
    int error_manager(int error_code, char *path);
    int print_man(void);
    int bin_to_int(char *bin);
    int file_size(char *path);
    int main(int ac, char **av);
    int compress_ppm(char *file, int size);
    int my_strcat_size(char *dest, char const *src, int size_file);
    int find_pos(char *file);
    int file_size(char *path);

    char *convert_file_to_bin(char *file, node_t *tree);
    char *add_tree(char *file, node_t *tree);
    char *convert_to_compressed(char *file, node_t *tree);
    char *extract_file(char *path);

    char **make_bin_arr(char *bin_file);
    char **make_file_arr(char *file, int size);

    node_t *create_huffman_tree(node_list_t *node_list);

    node_list_t *init_node_list(char *file);

#endif /* !TEK1_MY_H_ */
