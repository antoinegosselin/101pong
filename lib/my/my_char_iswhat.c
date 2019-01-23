/*
** EPITECH PROJECT, 2018
** my_char_iswhat.c
** File description:
** Regroups functions that knows about a char's state
*/

int my_char_islower(char const c)
{
    if (c >= 'a' && c <= 'z')
        return (1);
    else
        return (0);
}

int my_char_isupper(char const c)
{
    if (c >= 'A' && c <= 'Z')
        return (1);
    else
        return (0);
}

int my_char_isnum(char const c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else
        return (0);
}

int my_char_isalphanum(char const c)
{
    if (my_char_islower(c) || my_char_isupper(c) || my_char_isnum(c))
        return (1);
    else
        return (0);
}

int my_char_isprintable(char const c)
{
    if (c >= 32 && c <= 126)
        return (1);
    else
        return (0);
}
