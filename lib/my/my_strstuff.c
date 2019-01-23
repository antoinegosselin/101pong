/*
** EPITECH PROJECT, 2018
** my_strstuff.c
** File description:
** Regroups functions that does stuff on strings
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] == s2[i]) {
        if (s1[i] == '\0')
            return (0);
        i++;
    }
    return (s1[i] - s2[i]);
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (s1[i] == s2[i] && i < (n - 1)) {
        if (s1[i] == '\0')
            return (0);
        i++;
    }
    return (s1[i] - s2[i]);
}

char *my_strcpy(char *dest, char const *src)
{
    int i;

    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}

char *my_strncpy(char *dest, const char *src, int n)
{
    int i;
    int j;

    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];
    for (j = i; j < n; j++)
        dest[j] = '\0';
    return (dest);
}
