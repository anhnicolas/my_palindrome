/*
** EPITECH PROJECT, 2023
** B-SYN-200-LIL-2-1-palindrome-nicolas1.nguyen
** File description:
** palindrome2
*/

#include <palindrome.h>

void print_palindrome(all_t *all, int i)
{
    while (all->imin_copy <= all->imax) {
        if (convert_base(all->nb, all->base)
                    == convert_base(all->pal, all->base)) {
            all->check++;
            printf("%d leads to %d in %d iteration(s) in base %d\n", i,
                    all->pal, all->imin_copy, all->base);
            break;
        }
        procedure(all);
        all->imin_copy++;
    }
}

void palindromic_number_to_be_obtained(all_t *all, int ac, char **av)
{
    int i = 0;
    all->imin_copy = 0;
    all->check = 0;

    if (!(is_palindrome(convert_base(all->pal, all->base))))
        exit(84);
    while (convert_base(i, all->base) <= convert_base(all->pal, all->base)) {
        all->imin_copy = all->imin;
        all->nb = i;
        all->rev_nb = rev_int(all->nb, all->base);
        for (int i = 0; i < all->imin; i++)
            procedure(all);
        print_palindrome(all, i);
        i++;
    }
    if (all->check == 0)
        printf("no solution\n");
}
