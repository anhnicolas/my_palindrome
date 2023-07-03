/*
** EPITECH PROJECT, 2023
** B-SYN-200-LIL-2-1-sbmlparser-nicolas1.nguyen
** File description:
** my_str_to_word_array
*/

#include <my_utils.h>

int is_alphanum(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
        (c >= '0' && c <= '9') || c == '/' || c == '='
        || c == '"' || c == '-' || c == '.' || c == ':')
        return (1);
    else
        return (0);
}

int count_words(char const *str)
{
    int count = 0;
    int state = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_alphanum(str[i]))
            state = 0;
        if (state == 0) {
            state = 1;
            count++;
        }
    }
    return count;
}

char **my_str_to_word_array(char const *str)
{
    int i = 0; int a = 0; int start_word = 0;
    int length_word = 0; int c_words = count_words(str);
    char **tab = malloc(sizeof(char *) * (c_words + 1));
    int check = 0; int str_len = 0;

    for (; str[str_len] != '\0'; str_len++);
    for (; i < str_len + 1; i++) {
        if (is_alphanum(str[i]) && check == 0) {
            start_word = i; check = 1;
        }
        if (check == 1 && !is_alphanum(str[i])) {
            length_word = i - start_word;
            tab[a] = malloc(sizeof(char) * (length_word + 1));
            my_strncpy(tab[a], str + start_word, length_word);
            start_word = 0;
            a++; check = 0;
        }
    }
    tab[c_words] = NULL;
    return tab;
}
