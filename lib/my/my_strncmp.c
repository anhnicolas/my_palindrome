/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** my_strncmp
*/

#include <my_utils.h>

int my_strncmp(char *str1, char *str2, int n)
{
    if (my_strlen(str1) < n || my_strlen(str2) < n)
        return (-1);
    for (int i = 0; i != n; i++)
        if (str1[i] != str2[i])
            return (-1);
    return (0);
}
