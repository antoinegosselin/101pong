/*
** EPITECH PROJECT, 2018
** back.c
** File description:
** background of the window
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "bonus_pong.h"

window_t initialize_back(void)
{
    window_t back;

    back.texture = sfTexture_createFromFile("files/pong_back.png", NULL);
    back.sprite = sfSprite_create();
    return (back);
}

void print_back(sfRenderWindow *window, window_t back)
{
    sfRenderWindow_clear(window, sfBlack);
    sfSprite_setTexture(back.sprite, back.texture, sfTrue);
    sfRenderWindow_drawSprite(window, back.sprite, NULL);
}