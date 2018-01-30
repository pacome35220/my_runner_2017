/*
** EPITECH PROJECT, 2017
** parallax_back
** File description:
** parallax_back
*/

#include "proto.h"

void set_pos_back(objet_t *obj)
{
	if (obj->pos.x <= -WIDTH)
		obj->pos.x = 0;
	obj->pos.x -= obj->speed;
	sfSprite_setPosition(obj->sprite, obj->pos);
}

void set_pos_pipe(objet_t *obj, int *passed, int y, int level)
{
	if (obj->pos.x <= -52) {
		obj->pos.x = WIDTH;
		obj->pos.y = y;
		*passed = 0;
	}
	obj->speed = level * 2 + 5;
	obj->pos.x -= obj->speed;
	sfSprite_setPosition(obj->sprite, obj->pos);
}

void parallax_back(game_t *game)
{
	int height = game->settings.pipe_pos[game->window.score % 5];
	int gap = game->settings.gap[game->window.score % 5];

	LEVEL = SAVE_LEVEL + game->window.score / 5;
	set_pos_back(game->sky);
	set_pos_back(game->ground);
	set_pos_pipe(game->pipe_down, &game->passed, height - 600, LEVEL);
	set_pos_pipe(game->pipe_up, &game->passed, height + gap, LEVEL);
}
