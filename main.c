/*
** EPITECH PROJECT, 2023
** B-SYN-200-LIL-2-1-palindrome-nicolas1.nguyen
** File description:
** main
*/

#include <palindrome.h>

void usage(void)
{
    write(1, "USAGE\n", 7);
    write(1, "\t./palindrome -n number -p palindrome " , 39);
    write(1, "[-b base] [-imin i] [-imax i]\n", 31);
    write(1, "DESCRIPTION\n", 13);
    write(1, "\t-n n\t\tinteger to be transformed (>=0)\n", 40);
    write(1, "\t-p pal\t\tpalindromic number to be obtained", 43);
    write(1, " (incompatible with the -n option) (>=0)\n", 42);
    write(1, "\t\t\tif defined, all fitting values of n will be output\n", 55);
    write(1, "\t-b base\t\tbase in which the procedure will be executed", 55);
    write(1, " (1<b<=10) [def: 10]\n", 22);
    write(1, "\t-imin i\t\tminimum number of iterations, ", 41);
    write(1, "included (>=0) [def: 0]\n", 25);
    write(1, "\t-imax i\t\tmaximum number of iterations, ", 41);
    write(1, "included (>=0) [def: 100]\n", 27);
}

void error(all_t *all)
{
    if (all->nb < 0 || all->pal < 0 || all->base <= 1 || all->base > 10
        || all->imin < 0 || all->imax < 0 || all->imin > all->imax
        || all->error > 1)
        exit(84);
}

void args_gestion(all_t *all, int ac, char **av)
{
    for (int i = 0; av[i] != NULL; i++) {
        if (i > 0 && !is_odd(i) && is_digit(av[i]) == 84)
            exit(84);
        if (strcmp(av[i], "-n") == 0) {
            all->nb = atoi(av[i + 1]);
            all->error++;
        }
        if (strcmp(av[i], "-p") == 0) {
            all->pal = atoi(av[i + 1]);
            all->error++;
        }
        if (strcmp(av[i], "-b") == 0)
            all->base = atoi(av[i + 1]);
        if (strcmp(av[i], "-imin") == 0)
            all->imin = atoi(av[i + 1]);
        if (strcmp(av[i], "-imax") == 0)
            all->imax = atoi(av[i + 1]);
    }
    error(all);
}

int main(int ac, char **av)
{
    all_t *all = malloc(sizeof(all_t));
    all->base = 10;
    all->imin = 0;
    all->imax = 100;
    all->error = 0;

    if (ac < 2 || ac > 9 || ac == 4 || ac == 6 || ac == 8)
        return (84);
    if (strcmp(av[1], "-h") == 0) {
        usage();
        return 0;
    }
    args_gestion(all, ac, av);
    if (strcmp(av[1], "-n") == 0)
        integer_to_be_transformed(all, ac, av);
    if (strcmp(av[1], "-p") == 0)
        palindromic_number_to_be_obtained(all, ac, av);
    free(all);
    return 0;
}
