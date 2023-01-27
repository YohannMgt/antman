/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-yohann.mangenot
** File description:
** make_compressed_file
*/

#include "include/my.h"

char *char_to_str(char c)
{
    char *str = malloc(sizeof(char) * 2);
    str[0] = c;
    str[1] = '\0';
    return (str);
}

char *add_tree_line(node_t *node)
{
    if (node->code == NO_CODE)
        return ("");
    char *line = malloc(sizeof(char) * 15);
    my_strcpy(line, int_to_str(node->code));
    my_strcat(line, "\"");
    my_strcat(line, int_to_str(node->frequency));
    my_strcat(line, "!");
    return (line);
}

void add_tree_rec(node_t *node, char **dest)
{
    if (node == NULL)
        return;
    add_tree_rec(node->left, dest);
    my_strcat((*dest), add_tree_line(node));
    add_tree_rec(node->right, dest);
}

char * add_node_list(node_list_t *list, int size)
{
    char *result = malloc(sizeof(char) * (NOT_ZERO(size) + MAX_CHAR));
    for (int i = 0; i < list->node_number; i++) {
        my_strcat(result, int_to_str(list->list[i]->code));
        my_strcat(result, "\"");
        my_strcat(result, int_to_str(list->list[i]->frequency));
        my_strcat(result, "!");
    }
    return (result);
}

char *add_tree(char *file, node_t *tree)
{
    node_list_t *list = init_node_list(file);
    char *compressed = convert_to_compressed(file, tree);
    char *result = add_node_list(list, my_strlen(compressed));
    my_strcat(result, compressed);
    write(1, result, my_strlen(result));
    return (result);
}
