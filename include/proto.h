/*
** EPITECH PROJECT, 2017
** proto
** File description:
** proto
*/

#pragma once

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include "struct.h"

#define HEIGHT 956
#define WIDTH 495

#define SKY "ressources/sky.png"
#define GROUND "ressources/ground.png"
#define PIPE_UP "ressources/pipe_up.png"
#define PIPE_DOWN "ressources/pipe_down.png"
#define BIRD "ressources/bird.png"
#define FONT "ressources/font.ttf"
#define WING "ressources/wing.wav"
#define POINT "ressources/point.wav"
#define AHAHAH "ressources/ahahah.wav"

#define GRAVITY game->bird->delta_y
#define BIRD_X game->bird->pos.x
#define BIRD_Y game->bird->pos.y
#define PIPE_UP_X game->pipe_up->pos.x
#define PIPE_UP_Y game->pipe_up->pos.y
#define PIPE_DOWN_X game->pipe_down->pos.x
#define PIPE_DOWN_Y game->pipe_down->pos.y
#define SCORE game->window.score
#define BEST_SCORE game->window.best_score
#define TEXT game->window.text
#define BEST_TEXT game->window.best_text
#define LEVEL game->settings.level
#define SAVE_LEVEL game->settings.save_level

#define POS_X(bird, pipe) (bird + 17 >= pipe && bird - 17 <= pipe + 52 ? 1 : 0)

int my_strlen(char const *str);
void my_putchar(char c);
void my_putstr(char const *str);
char *concat(char *recept, char *new);

FILE *fopen_file(int argc, char **argv, char **env);
setting_t parsing(FILE *file);
void h_option(void);
win_t create_window(char *name);
void check_event(win_t *window, objet_t *bird);
game_t init_game_object(setting_t settings, win_t window);
objet_t *create_object(char *path, sfVector2f pos, float s);
void parallax_back(game_t *game);
void move_bird(game_t *game, sfClock *clock);
void print_score(game_t *game);
void draw_all(win_t *win, game_t *game);
void destroy_free(game_t *game, sfClock *clock);
