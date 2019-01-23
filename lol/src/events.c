/*
** EPITECH PROJECT, 2018
** events.c
** File description:
** all the events from my_hunter
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "bonus_pong.h"

sfVector2f manage_mouse_move(sfEvent mouse_move, sfVector2f position)
{
    position.x = mouse_move.mouseMove.x - 25;
    position.y = mouse_move.mouseMove.y - 25;
    return (position);
}

sfVector2f manage_mouse_click(sfEvent mouse_click, sfVector2f position)
{
    if (mouse_click.mouseButton.button == sfMouseLeft) {
        position.x = mouse_click.mouseButton.x - 25;
        position.y = mouse_click.mouseButton.y - 25;
    }
    return (position);
}