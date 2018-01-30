/*
** EPITECH PROJECT, 2017
** struct
** File description:
** struct
*/

#pragma once

typedef struct
{
	sfTexture *texture;
	sfSprite *sprite;
	sfIntRect rect;
	sfVector2f pos;
	float speed;
	float delta_y;
}objet_t;

typedef struct
{
	int level;
	int save_level;
	int pipe_pos[5];
	int gap[5];
}setting_t;

typedef struct
{
	sfRenderWindow *window;
	sfEvent event;
	sfFont* font;
	sfText* text;
	sfText* best_text;
	int score;
	int best_score;
	sfMusic *ahahah;
	sfMusic *wing;
	sfMusic *point;
}win_t;

typedef struct
{
	objet_t *sky;
	objet_t *ground;
	objet_t *pipe_up;
	objet_t *pipe_down;
	objet_t *bird;
	setting_t settings;
	win_t window;
	int passed;
}game_t;
