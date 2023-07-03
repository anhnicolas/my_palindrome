/*
** EPITECH PROJECT, 2023
** B-SYN-200-LIL-2-1-palindrome-nicolas1.nguyen
** File description:
** requirement
*/

#include <stdio.h>

int my_factrec_synthesis(int nb)
{
    if (nb < 0 || nb > 12)
        return (0);
    if (nb == 1 || nb == 0)
        return (1);
    if (nb >= 1)
        return (nb * my_factrec_synthesis(nb - 1));
}

int my_squareroot(int i, int nb)
{
    if (nb == 0)
        return 0;
    if (nb < 0)
        return -1;
    if (i * i == nb)
        return (i);
    if (i * i > nb)
        return (-1);
    return (my_squareroot(i + 1, nb));
}

int my_squareroot_synthesis(int nb)
{
    return (my_squareroot(1, nb));
}
