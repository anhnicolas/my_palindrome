/*
** EPITECH PROJECT, 2023
** B-SYN-200-LIL-2-1-palindrome-nicolas1.nguyen
** File description:
** tools
*/

#include <palindrome.h>

int is_odd(int num)
{
    if (num % 2 != 0) {
        return 1;
    } else {
        return 0;
    }
}

int is_digit(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (isdigit(str[i]) == 0)
            return 84;
        i++;
    }
    return 0;
}
