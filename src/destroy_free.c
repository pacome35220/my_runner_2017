/*
** EPITECH PROJECT, 2017
** destroy_free
** File description:
** destroy_free
*/

#include <stdlib.h>
#include "proto.h"

void my_free(objet_t *a, objet_t *b, objet_t *c, objet_t *d)
{
	free(a);
	free(b);
	free(c);
	free(d);
}

void destroy_free(game_t *game, sfClock *clock)
{
	sfSprite_destroy(game->sky->sprite);
	sfSprite_destroy(game->ground->sprite);
	sfSprite_destroy(game->pipe_up->sprite);
	sfSprite_destroy(game->pipe_down->sprite);
	sfSprite_destroy(game->bird->sprite);
	sfTexture_destroy(game->sky->texture);
	sfTexture_destroy(game->ground->texture);
	sfTexture_destroy(game->pipe_up->texture);
	sfTexture_destroy(game->pipe_down->texture);
	sfTexture_destroy(game->bird->texture);
	sfText_destroy(game->window.text);
	sfText_destroy(game->window.best_text);
	sfFont_destroy(game->window.font);
	sfRenderWindow_destroy(game->window.window);
	sfClock_destroy(clock);
	my_free(game->sky, game->ground, game->pipe_up, game->pipe_down);
	free(game->bird);
	sfMusic_destroy(game->window.wing);
	sfMusic_destroy(game->window.point);
	sfMusic_destroy(game->window.ahahah);
}
