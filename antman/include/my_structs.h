/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-yohann.mangenot
** File description:
** my_structs
*/

#include "my.h"

#ifndef B_CPE_110_LYN_1_1_ANTMAN_YOHANN_MANGENOT_MY_STRUCTS_H_
    #define B_CPE_110_LYN_1_1_ANTMAN_YOHANN_MANGENOT_MY_STRUCTS_H_

typedef struct node {
    struct node *left;
    struct node *right;
    int code;
    int frequency;
    char *binary;
} node_t;

typedef struct node_list {
    node_t **list;
    int node_number;
} node_list_t;

typedef struct dict {
    char *val;
    int rec;
} dict_t;

typedef struct ppm {
    char **file_arr;
    dict_t **compress_file;
    int nb_seq;
    char *new_file;
    int size_file;
} ppm_t;

#endif /* !B_CPE_110_LYN_1_1_ANTMAN_YOHANN_MANGENOT_MY_STRUCTS_H_ */
