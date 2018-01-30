/*
** EPITECH PROJECT, 2017
** create_object
** File description:
** create_object
*/

#include <stdlib.h>
#include <stdio.h>
#include "proto.h"

objet_t *create_object(char *path, sfVector2f pos, float s)
{
	objet_t *object = malloc(sizeof(*object));

	if (object == NULL)
		return (NULL);
	object->texture = sfTexture_createFromFile(path, NULL);
	object->sprite = sfSprite_create();
	object->pos = pos;
	object->speed = s;
	sfSprite_setTexture(object->sprite, object->texture, sfTrue);
	return (object);
}
