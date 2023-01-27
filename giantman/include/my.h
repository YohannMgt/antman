/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-yohann.mangenot
** File description:
** my
*/

#ifndef TEK1_MY_H_
    #define TEK1_MY_H_

    #define MIN(x, y)           (((x) < (y)) ? (x) : (y))
    #define MAX(x, y)           (((x) > (y)) ? (x) : (y))
    #define ABS(x)              ((x) > 0) ? (x) : (-x)
    #define RAD_TO_DEGRES(x)    (x) * (180 / PI)
    #define NOT_NEG(x)         ((x) < 0) ? 0 : (x)
    #define UP(x)               ((x) < 0) ? 0 : (x)
    #define NOT_ZERO(x)         ((x) <= 0) ? 1 : (x)

    #define PI                  3.14159

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
    #define ERR_GIANT_MAN       6
    #define ERR_FOLD            7

    #define HELP                ", use -h to display help\n"
    #define ERR_ARGS_MSG        "Bad argument number"HELP
    #define ERR_TYPE_MSG        "Bad file type"HELP
    #define ERR_EXEC_MSG        "Compression error\n"
    #define ERR_ALGO_MSG        "Couldn't find an algorithm for this file"HELP
    #define ERR_GIANT_MAN_MSG    GIANTMAN_MAN" does not exist\n"
    #define ERR_FOLD_MSG        "Cannot open a folder"HELP

    #define GIANTMAN_MAN        "giantman_man.txt"

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

    int error_manager(int error_code, char *path);
    int print_man(void);
    int decompress_txt(char *file);
    int my_strcat_size(char *dest, char const *src, int size_file);
    int check_size(node_list_t *list, node_t *tree);
    int file_size(char *path);

    char *int_to_bin(unsigned int nb);

    char **make_dictionary(char *file);

    node_list_t *dict_to_node(char **dict, int element_number);

    node_t *init_tree(char **file);
    int decompress_ppm(char *file, int size);
    int find_pos(char *file);
    int my_strcat_size(char *dest, char const *src, int size_file);
    void create_sequence(ppm_t *ppm);


#endif /* !TEK1_MY_H_ */
