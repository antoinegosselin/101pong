/*
** EPITECH PROJECT, 2018
** bonus_pong.h
** File description:
** prototypes from my_hunter
*/

#ifndef MY_HUNTER_H_
#define MY_HUNTER_H_

#include <SFML/Audio.h>

typedef struct window_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
} window_t;

typedef struct time_s
{
    sfClock *clock;
    sfTime time;
    float seconds;
} my_time_t;

typedef struct settings_s
{
    int music;
    int level;
    sfVector2f pos;
    sfMusic *song;
    int score_left;
    int score_right;
    int player;
} options_t;

typedef struct pictures_s
{
    window_t pic1;
    window_t pic2;
} pic_t;
typedef struct raquette_pos_s
{
    float x;
    float y_low;
    float y_high;
} raq_pos_t;
typedef struct raquettes_s
{
    raq_pos_t gauche;
    raq_pos_t droite;
} raquette_t;
sfVector2f manage_mouse_move(sfEvent mouse_move, sfVector2f position);
sfVector2f manage_mouse_click(sfEvent mouse_click, sfVector2f position);
void move_rect(sfIntRect *rect, int offset, int max_value);
void print_back(sfRenderWindow *window, window_t back);
void analyze_event(sfRenderWindow *window, sfEvent event, options_t *game,
                                        sfVector2f *raquette_gauche_position,
                                        sfVector2f *raquette_droite_position);
sfVector2f print_ball(sfRenderWindow *window, sfVector2f ball_speed,
                                    sfVector2f ball_position, window_t ball);
window_t initialize_back(void);
window_t initialize_ball(void);
window_t initialize_menu(void);
window_t initialize_menum(void);
sfIntRect initialize_rect(int size);
options_t *click_event(sfRenderWindow *window, sfEvent click, options_t *game);
options_t *analyze_menu_event(sfRenderWindow *window, sfEvent click,
                                options_t *game);
void do_actions(sfRenderWindow *window, options_t *game);
void set_menu(sfRenderWindow *window);
int set_music(options_t *game);
void display_picture(sfRenderWindow *window, window_t back, options_t *game);
void print_menu(sfRenderWindow *window, pic_t menu, options_t *game);
options_t *initialize_options(void);
sfVector2f print_cible(sfRenderWindow *window, sfVector2f pos);
window_t initialize_cible(void);
options_t *select_level(sfRenderWindow *window, options_t *game);
int level_event(options_t *game, sfEvent click);
sfVector2f speed_change(sfRenderWindow *window, sfVector2f speed,
                        sfVector2f *ball_position, options_t *game,
                        sfVector2f raquette_gauche_position,
                        sfVector2f raquette_droite_position);
window_t init_score(void);
void print_score(sfRenderWindow *window, options_t *game,
                                        window_t score_player1,
                                        window_t score_player2);
void set_score(sfRenderWindow *window, int player_nb, options_t *game);
raq_pos_t init_raquette_pos(int x);
window_t init_raquette(void);
void print_raquettes(sfRenderWindow *window, window_t raquette_gauche,
                        window_t raquette_droite,
                        sfVector2f raquette_gauche_position,
                        sfVector2f raquette_droite_position);

#endif
