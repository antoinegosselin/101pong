/*
** EPITECH PROJECT, 2018
** menu.c
** File description:
** menu of the game
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "bonus_pong.h"

window_t initialize_menu(void)
{
    window_t menu;

    menu.texture = sfTexture_createFromFile("files/menu.png", NULL);
    menu.sprite = sfSprite_create();
    return (menu);
}

window_t initialize_menum(void)
{
    window_t menu;

    menu.texture = sfTexture_createFromFile("files/menum.png", NULL);
    menu.sprite = sfSprite_create();
    return (menu);
}

void do_actions(sfRenderWindow *window, options_t *game)
{
    window_t back = initialize_back();

    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    display_picture(window, back, game);
}

void print_menu(sfRenderWindow *window, pic_t menu, options_t *game)
{
    if (game->music == 1) {
        sfSprite_setTexture(menu.pic1.sprite, menu.pic1.texture, sfTrue);
        sfRenderWindow_drawSprite(window, menu.pic1.sprite, NULL);
    }
    if (game->music == 0) {
        sfSprite_setTexture(menu.pic2.sprite, menu.pic2.texture, sfTrue);
        sfRenderWindow_drawSprite(window, menu.pic2.sprite, NULL);
    }
    sfRenderWindow_display(window);
}

void set_menu(sfRenderWindow *window)
{
    pic_t menu;
    options_t *game = initialize_options();
    sfEvent event;

    menu.pic1 = initialize_menu();
    menu.pic2 = initialize_menum();
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_setMouseCursorVisible(window, sfTrue);
        sfRenderWindow_clear(window, sfBlack);
        print_menu(window, menu, game);
        while (sfRenderWindow_pollEvent(window, &event))
            game = analyze_menu_event(window, event, game);
    }
    sfTexture_destroy(menu.pic1.texture);
    sfSprite_destroy(menu.pic1.sprite);
    sfTexture_destroy(menu.pic2.texture);
    sfSprite_destroy(menu.pic2.sprite);
    sfMusic_destroy(game->song);
}