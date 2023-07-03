/*
** EPITECH PROJECT, 2022
** B-CPE-100-LIL-1-1-cpoolday06-nicolas1.nguyen
** File description:
** my_strcpy
*/

#include <my_utils.h>

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
