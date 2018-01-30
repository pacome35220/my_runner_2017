/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <stdlib.h>
#include <stdio.h>
#include "proto.h"

int main(int argc, char **argv, char **env)
{
	win_t window;
	sfClock *clock;
	game_t game;
	FILE *file = fopen_file(argc, argv, env);

	if (file == NULL)
		return (84);
	clock = sfClock_create();
	window = create_window("Flappy Bird");
	if (window.window == NULL)
		return (84);
	game = init_game_object(parsing(file), window);
	while (sfRenderWindow_isOpen(window.window)) {
		check_event(&window, game.bird);
		move_bird(&game, clock);
		parallax_back(&game);
		print_score(&game);
		draw_all(&window, &game);
	}
	destroy_free(&game, clock);
	return (0);
}
