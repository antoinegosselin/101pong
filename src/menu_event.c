/*
** EPITECH PROJECT, 2018
** menu_event.c
** File description:
** check menu events
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "bonus_pong.h"

options_t *click_event(sfRenderWindow *window, sfEvent click, options_t *game)
{
    int m_x = click.mouseButton.x;
    int m_y = click.mouseButton.y;

    game->pos = manage_mouse_click(click, game->pos);
    if ((m_x >= 760) && (m_x <= 860) && (m_y >= 540) && (m_y <= 590))
        sfRenderWindow_close(window);
    if ((m_x >= 360) && (m_x <= 545) && (m_y >= 220) && (m_y <= 274)) {
        game->player = 1;
        do_actions(window, game);
    }
    if ((m_x >= 360) && (m_x <= 545) && (m_y >= 323) && (m_y <= 380)) {
        game->player = 2;
        do_actions(window, game);
    }
    if ((m_x >= 360) && (m_x <= 545) && (m_y >= 430) && (m_y <= 480))
       game = select_level(window, game);
    if ((m_x >= 0) && (m_x <= 60) && (m_y >= 540) && (m_y <= 600))
        game->music = set_music(game);
    return (game);
}

options_t *analyze_menu_event(sfRenderWindow *window, sfEvent event,
                                options_t *game)
{
    if (event.type == sfEvtClosed /*|| event.key.code == sfKeyEscape*/)
        sfRenderWindow_close(window);
    if (event.type == sfEvtKeyPressed)
        if (event.key.code == sfKeyF5)
            game->music = set_music(game);
    if (event.type == sfEvtMouseMoved)
        game->pos = manage_mouse_move(event, game->pos);
    if (event.type == sfEvtMouseButtonPressed)
        if (event.mouseButton.button == sfMouseLeft)
            game = click_event(window, event, game);
    return (game);
}