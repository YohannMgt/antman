/*
** EPITECH PROJECT, 2022
** B-CPE-101-LYN-1-1-myprintf-mael.rabot
** File description:
** plus_bin_functions.c
*/

#include "../include/my_printf.h"

char *plus_flag_d(int number, int prc)
{
    char res[32];
    int number_is_neg = (number < 0) ? 1 : 0;
    number = (number < 0) ? -number : number;
    char *tmp;
    int sum = 0;
    while (number > 0) {
        res[sum] = number % 10 + 48;
        number = number / 10;
        sum++;
    }
    tmp = malloc(sum + 1);
    if (number_is_neg == 1)
        tmp[0] = '-';
    else
        tmp[0] = '+';
    for (int j = sum - 1; j >= 0; j--) {
        tmp[(sum + 1) - j - 1] = res[j];
    }
    tmp[sum + 1] = '\0';
    return (tmp);
}

static char *char_to_sting(char c)
{
    char *str = malloc(sizeof(char) * 2);
    str[0] = c;
    str[1] = '\0';
    return (str);
}

char *plus_flag_u(unsigned int number)
{
    char *res;
    if (number >= 10)
        my_strcat(res, plus_flag_u(number / 10));
    my_strcat(res, char_to_sting((char)((number % 10) + 48)));
    return (res);
}
