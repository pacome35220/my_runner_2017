/*
** EPITECH PROJECT, 2017
** move_bird
** File description:
** move_bird
*/

#include "proto.h"

void flap_wings(sfIntRect *rect)
{
	if (rect->left < 68)
		rect->left += 34;
	else
		rect->left = 0;
}

void maybe_kill_bird(game_t *game)
{
	if (BIRD_Y - 12 <= PIPE_DOWN_Y + 600)
		*game = init_game_object(game->settings, game->window);
	else if (BIRD_Y + 12 >= PIPE_UP_Y)
		*game = init_game_object(game->settings, game->window);
	if (game->passed == 0) {
		game->passed = 1;
		game->window.score++;
		sfMusic_play(game->window.point);
	}
}

void move_bird(game_t *game, sfClock *clock)
{
	sfSprite_setPosition(game->bird->sprite, game->bird->pos);
	if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) >= 0.1) {
		flap_wings(&game->bird->rect);
		sfClock_restart(clock);
	}
	game->bird->pos.y += game->bird->delta_y;
	GRAVITY += 2;
	if (GRAVITY > 0 && GRAVITY * 3 < 90)
		sfSprite_setRotation(game->bird->sprite, GRAVITY * 3);
	if (BIRD_Y > HEIGHT - 190)
		BIRD_Y = HEIGHT - 190;
	if (POS_X(BIRD_X, PIPE_UP_X))
		maybe_kill_bird(game);
}
