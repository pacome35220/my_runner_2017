/*
** EPITECH PROJECT, 2017
** create_window
** File description:
** create_window
*/

#include <stdlib.h>
#include "proto.h"

win_t create_window(char *name)
{
	win_t window;
	sfVideoMode mode = {WIDTH, HEIGHT, 32};
	sfVector2i pos = {1920 / 2 - WIDTH / 2, 0};

	window.window = sfRenderWindow_create(mode, name, sfClose, NULL);
	sfRenderWindow_setFramerateLimit(window.window, 30);
	sfRenderWindow_setPosition(window.window, pos);
	window.font = sfFont_createFromFile(FONT);
	window.text = sfText_create();
	window.best_text = sfText_create();
	window.best_score = 0;
	window.wing = sfMusic_createFromFile(WING);
	window.ahahah = sfMusic_createFromFile(AHAHAH);
	sfMusic_setLoop(window.ahahah, sfTrue);
	sfMusic_setVolume(window.ahahah, 60);
	sfMusic_play(window.ahahah);
	window.point = sfMusic_createFromFile(POINT);
	return (window);
}
