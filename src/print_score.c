/*
** EPITECH PROJECT, 2017
** print_score
** File description:
** print_score
*/

#include <stdlib.h>
#include <stdio.h>
#include "proto.h"

sfVector2f vecf(float x, float y)
{
	sfVector2f pos = {x, y};

	return (pos);
}

int my_intlen(int a)
{
	int counter = 0;

	if (a > 9) {
		counter += my_intlen(a / 10);
		return (counter + 1);
	}
	else
		return (1);
}

char *my_stock_nbr(int nb)
{
	int len = my_intlen(nb);
	char *str = malloc(sizeof(*str) * (len + 1));

	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	len--;
	while (len >= 0) {
		str[len] = nb % 10 + '0';
		nb = nb / 10;
		len--;
	}
	return (str);
}

void put_text(sfText* text, char *str, sfFont* font, sfVector2f pos)
{
	sfText_setString(text, str);
	sfText_setFont(text, font);
	sfText_setCharacterSize(text, 25);
	sfText_setPosition(text, pos);
}

void print_score(game_t *game)
{
	char *score = my_stock_nbr(SCORE);
	char *best_score = my_stock_nbr(BEST_SCORE);

	if (SCORE > BEST_SCORE)
		BEST_SCORE = SCORE;
	put_text(TEXT, score, game->window.font, vecf(20, 20));
	put_text(BEST_TEXT, best_score, game->window.font, vecf(20, 60));
	free(score);
	free(best_score);
}
