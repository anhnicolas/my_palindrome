/*
** EPITECH PROJECT, 2023
** B-SYN-200-LIL-2-1-palindrome-nicolas1.nguyen
** File description:
** palindrome
*/

#include <my_printf.h>
#include <my_utils.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

#ifndef PALINDROME_H_
    #define PALINDROME_H_

typedef struct all_s {
    int nb;
    int pal;
    int rev_nb;
    int base;
    int imin;
    int imin_copy;
    int imax;
    int check;
    int error;
} all_t;

void integer_to_be_transformed(all_t *all, int ac, char **av);
void palindromic_number_to_be_obtained(all_t *all, int ac, char **av);
int is_palindrome(int nb);
void procedure(all_t *all);
int rev_int(int nb, int base);
int is_odd(int num);
int is_digit(char *str);

#endif /* !PALINDROME_H_ */
