/*
** EPITECH PROJECT, 2017
** fopen_file
** File description:
** fopen_file
*/

#include "proto.h"

FILE *fopen_file(int argc, char **argv, char **env)
{
	FILE *file;

	if (*env == NULL) {
		my_putstr("Non, il faut des variables d'environnement");
		my_putstr(" ! Pas de env -i !\n");
		return (NULL);
	}
	if (argc != 2 || ((file = fopen(argv[1], "r")) == NULL)) {
		h_option();
		return (NULL);
	}
	return (file);
}
