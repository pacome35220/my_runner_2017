/*
** EPITECH PROJECT, 2017
** draw_all
** File description:
** draw_all
*/

#include "proto.h"

void draw_all(win_t *win, game_t *game)
{
	sfRenderWindow_clear(win->window, sfBlack);
	sfRenderWindow_drawSprite(win->window, game->sky->sprite, NULL);
	sfRenderWindow_drawSprite(win->window, game->pipe_up->sprite, NULL);
	sfRenderWindow_drawSprite(win->window, game->pipe_down->sprite, NULL);
	sfRenderWindow_drawSprite(win->window, game->ground->sprite, NULL);
	sfSprite_setTextureRect(game->bird->sprite, game->bird->rect);
	sfRenderWindow_drawSprite(win->window, game->bird->sprite, NULL);
	sfRenderWindow_drawText(win->window, win->text, NULL);
	sfRenderWindow_drawText(win->window, win->best_text, NULL);
	sfRenderWindow_display(win->window);
}
