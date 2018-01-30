/*
** EPITECH PROJECT, 2017
** init_game_object
** File description:
** init_game_object
*/

#include "proto.h"

sfVector2f posf(float x, float y)
{
	sfVector2f pos = {x, y};

	return (pos);
}

game_t init_game_object(setting_t settings, win_t window)
{
	game_t game;
	int level = settings.save_level;
	sfVector2f origin = {17, 12};
	sfIntRect rect = {0, 0, 34, 24};
	int y = WIDTH + 100;

	window.score = 0;
	game.window = window;
	game.settings = settings;
	game.passed = 0;
	game.sky = create_object(SKY, posf(0, 0), 2 * level);
	game.ground = create_object(GROUND, posf(0, HEIGHT - 200), 3 * level);
	game.pipe_up = create_object(PIPE_UP, posf(y, 500), 5 * level);
	game.pipe_down = create_object(PIPE_DOWN, posf(y, -300), 5 * level);
	game.bird = create_object(BIRD, posf(WIDTH / 4, HEIGHT / 2), 0);
	game.bird->delta_y = 1;
	game.bird->rect = rect;
	sfSprite_setOrigin(game.bird->sprite, origin);
	return (game);
}
