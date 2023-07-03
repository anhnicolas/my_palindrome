/*
** EPITECH PROJECT, 2023
** B-SYN-200-LIL-2-1-palindrome-nicolas1.nguyen
** File description:
** palindrome
*/

#include <palindrome.h>

int rev_int(int nb, int base)
{
    int rev_nb = 0;
    int temp = 0;

    while (nb != 0) {
        temp = nb % base;
        rev_nb = rev_nb * base + temp;
        nb = nb / base;
    }
    return rev_nb;
}

int is_palindrome(int nb)
{
    int temp = nb;
    int rev = 0;
    int cache = 0;

    while (temp > 0) {
        cache = temp % 10;
        rev = rev * 10 + cache;
        temp /= 10;
    }
    if (rev == nb)
        return 1;
    return 0;
}

void procedure(all_t *all)
{
    int temp = all->nb;
    all->nb = temp + all->rev_nb;
    all->rev_nb = rev_int(all->nb, all->base);
}

void integer_to_be_transformed(all_t *all, int ac, char **av)
{
    all->rev_nb = rev_int(all->nb, all->base);
    for (int i = 0; i < all->imin; i++)
        procedure(all);
    while (!is_palindrome(convert_base(all->nb, all->base))) {
        if (all->imin >= all->imax) {
            printf("no solution\n");
            return;
        }
        procedure(all);
        all->imin++;
    }
    printf("%s leads to %d in %d iteration(s) in base %d\n", av[2],
                all->nb, all->imin, all->base);
}
