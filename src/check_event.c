/*
** EPITECH PROJECT, 2017
** check_event
** File description:
** check_event
*/

#include "proto.h"

void maybe_space(int *bool, objet_t *bird, win_t *window)
{
	if (*bool == 1) {
		bird->delta_y = -18;
		sfSprite_setRotation(bird->sprite, -20);
		sfMusic_play(window->wing);
		*bool = 0;
	}
}

void check_event(win_t *window, objet_t *bird)
{
	static int bool = 1;
	int y = bird->pos.y;

	while (sfRenderWindow_pollEvent(window->window, &window->event)) {
		if (window->event.type == sfEvtClosed)
			sfRenderWindow_close(window->window);
		if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
			sfRenderWindow_close(window->window);
		if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue && y > 0)
			maybe_space(&bool, bird, window);
		else
			bool = 1;
	}
}
