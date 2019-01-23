/*
** EPITECH PROJECT, 2018
** level.c
** File description:
** select level of the game
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "bonus_pong.h"

int level_event(options_t *game, sfEvent click)
{
    int m_x = click.mouseButton.x;
    int m_y = click.mouseButton.y;

    if (click.mouseButton.button == sfMouseLeft) {
        if ((m_x >= 0) && (m_x < 450) && (m_y >= 0) && (m_y < 300))
            game->level = 1;
        if ((m_x >= 450) && (m_x <= 900) && (m_y >= 0) && (m_y < 300))
            game->level = 3;
        if ((m_x >= 0) && (m_x < 450) && (m_y >= 300) && (m_y <= 600))
            game->level = 5;
        if ((m_x >= 450) && (m_x <= 9000) && (m_y >= 300) && (m_y <= 600))
            game->level = 10;
    }
    return (game->level);
}

window_t initialize_level(void)
{
    window_t level;

    level.texture = sfTexture_createFromFile("files/level.png", NULL);
    level.sprite = sfSprite_create();
    return (level);
}

void print_level(sfRenderWindow *window, window_t level)
{
    sfRenderWindow_clear(window, sfBlack);
    sfSprite_setTexture(level.sprite, level.texture, sfTrue);
    sfRenderWindow_drawSprite(window, level.sprite, NULL);
    sfRenderWindow_display(window);
}

options_t *select_level(sfRenderWindow *window, options_t *game)
{
    sfEvent click;
    window_t level = initialize_level();

    while (sfRenderWindow_isOpen(window)) {
        print_level(window, level);
        while (sfRenderWindow_pollEvent(window, &click)) {
            if (click.type == sfEvtMouseButtonPressed) {
                game->level = level_event(game, click);
                game->pos = manage_mouse_click(click, game->pos);
                return (game);
            }
            if (click.type == sfEvtMouseMoved)
                game->pos = manage_mouse_move(click, game->pos);
        }
    }
    return (game);
}