/*
** EPITECH PROJECT, 2018
** score.c
** File description:
** Functions about the score management
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "bonus_pong.h"

window_t init_score(void)
{
    window_t score;

    score.texture = sfTexture_createFromFile("files/score.png", NULL);
    score.sprite = sfSprite_create();
    score.rect = initialize_rect(100);
    sfSprite_setTextureRect(score.sprite, score.rect);
    return (score);
}

void show_victory(sfRenderWindow *window, int player_nb, options_t *game)
{
    window_t winner;
    sfEvent win;
    sfMusic *win_song;

    win_song = sfMusic_createFromFile("files/win.ogg");
    sfMusic_stop(game->song);
    sfMusic_play(win_song);
    if (player_nb == 1) {
        winner.texture = sfTexture_createFromFile("files/win1.png", NULL);
        winner.sprite = sfSprite_create();
    }
    if (player_nb == 2) {
        winner.texture = sfTexture_createFromFile("files/win2.png", NULL);
        winner.sprite = sfSprite_create();
    }
    sfRenderWindow_clear(window, sfBlack);
    sfSprite_setTexture(winner.sprite, winner.texture, sfTrue);
    sfRenderWindow_drawSprite(window, winner.sprite, NULL);
    sfRenderWindow_display(window);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &win)) {
            if (win.type == sfEvtKeyPressed) {
                if (win.key.code == sfKeyM) {
                    sfMusic_stop(win_song);
                    sfMusic_destroy(win_song);
                    set_menu(window);
                }
            }
            if (win.type == sfEvtClosed || win.key.code == sfKeyEscape) {
                sfMusic_stop(win_song);
                sfMusic_destroy(win_song);
                sfRenderWindow_close(window);
                sfRenderWindow_destroy(window);
            }
        }
    }
    sfTexture_destroy(winner.texture);
    sfSprite_destroy(winner.sprite);
}

void set_score(sfRenderWindow *window, int player_nb, options_t *game)
{
    if (player_nb == 1) {
        game->score_left++;
        if (game->score_left > 6)
            show_victory(window, 1, game);
    }
    else {
        game->score_right++;
        if (game->score_right > 6)
            show_victory(window, 2, game);
    }
}

static sfIntRect init_rect(int size)
{
    sfIntRect rect;

    rect.top = 0;
    rect.left = size;
    rect.width = 100;
    rect.height = size + 100;
    return (rect);
}

void print_score(sfRenderWindow *window, options_t *game,
                                        window_t score_player1,
                                        window_t score_player2)
{
    sfVector2f const pos_score1 = {330, 25};
    sfVector2f const pos_score2 = {470, 25};

    sfSprite_setTexture(score_player1.sprite, score_player1.texture, sfTrue);
    sfSprite_setTexture(score_player2.sprite, score_player2.texture, sfTrue);
    score_player1.rect = init_rect(game->score_left * 100);
    score_player2.rect = init_rect(game->score_right * 100);
    sfSprite_setTextureRect(score_player1.sprite, score_player1.rect);
    sfSprite_setTextureRect(score_player2.sprite, score_player2.rect);
    sfSprite_setPosition(score_player1.sprite, pos_score1);
    sfSprite_setPosition(score_player2.sprite, pos_score2);
    sfRenderWindow_drawSprite(window, score_player1.sprite, NULL);
    sfRenderWindow_drawSprite(window, score_player2.sprite, NULL);
}
