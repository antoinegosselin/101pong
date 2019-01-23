/*
** EPITECH PROJECT, 2018
** my_hunter.c
** File description:
** my_hunter
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "bonus_pong.h"

unsigned int const WIDTH = 900;
unsigned int const HEIGHT = 600;
int const BITS_PER_FRAME = 32;
const sfVideoMode MODE = {WIDTH, HEIGHT, BITS_PER_FRAME};

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left == max_value)
        rect->left = 0;
}

sfIntRect initialize_rect(int size)
{
    sfIntRect rect;

    rect.top = 0;
    rect.left = 0;
    rect.width = size;
    rect.height = size;
    return (rect);
}

void analyze_event(sfRenderWindow *window, sfEvent event, options_t *game,
                                        sfVector2f *raquette_gauche_position,
                                        sfVector2f *raquette_droite_position)
{
    if (event.type == sfEvtClosed || event.key.code == sfKeyEscape)
        sfRenderWindow_close(window);
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyF5)
            game->music = set_music(game);
        if (event.key.code == sfKeyM) {
            sfMusic_stop(game->song);
            set_menu(window);
        }
        if (event.key.code == sfKeyZ)
            raquette_gauche_position->y = raquette_gauche_position->y - 20 * (game->level / 2);
        if (event.key.code == sfKeyS)
            raquette_gauche_position->y = raquette_gauche_position->y + 20 * (game->level / 2);
        if (game->player == 2) {
            if (event.key.code == sfKeyUp)
                raquette_droite_position->y = raquette_droite_position->y - 20 * (game->level / 2);
            if (event.key.code == sfKeyDown)
                raquette_droite_position->y = raquette_droite_position->y + 20 * (game->level / 2);
        }
    }
}

void display_picture(sfRenderWindow *window, window_t back, options_t *game)
{
    sfVector2f ball_speed = {4, -4};
    sfVector2f ball_position = {435, 285};
    sfVector2f raquette_gauche_position;
    sfVector2f raquette_droite_position;
    sfEvent event;
    window_t ball = initialize_ball();
    window_t score_player1 = init_score();
    window_t score_player2 = init_score();
    window_t raquette_gauche = init_raquette();
    window_t raquette_droite = init_raquette();
    raquette_t *raquettes = malloc(sizeof(raq_pos_t) * 2);

    raquettes->gauche = init_raquette_pos(0);
    raquettes->droite = init_raquette_pos(880);
    raquette_gauche_position.x = raquettes->gauche.x;
    raquette_droite_position.x = raquettes->droite.x;
    raquette_gauche_position.y = raquettes->gauche.y_high;
    raquette_droite_position.y = raquettes->droite.y_high;
    ball_speed.x = ball_speed.x * game->level;
    ball_speed.y = ball_speed.y * game->level;
    while (sfRenderWindow_isOpen(window)) {
        print_back(window, back);
        print_score(window, game, score_player1, score_player2);
        print_raquettes(window, raquette_gauche, raquette_droite, raquette_gauche_position, raquette_droite_position);
        ball_position = print_ball(window, ball_speed, ball_position, ball);
        while (sfRenderWindow_pollEvent(window, &event))
            analyze_event(window, event, game, &raquette_gauche_position, &raquette_droite_position);
        ball_speed = speed_change(window, ball_speed, &ball_position, game, raquette_gauche_position, raquette_droite_position);
        if (game->player == 1) {
            raquette_droite_position.y = ball_position.y - 60;
        }
        sfRenderWindow_display(window);
    }
    sfTexture_destroy(back.texture);
    sfSprite_destroy(back.sprite);
    sfTexture_destroy(ball.texture);
    sfSprite_destroy(ball.sprite);
    free(raquettes);
}

int main(void)
{
    sfRenderWindow *window = sfRenderWindow_create(MODE, "Pong",
                                                    sfDefaultStyle, NULL);

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_setFramerateLimit(window, 60);
        set_menu(window);
    }
    sfRenderWindow_destroy(window);
    return (0);
}
