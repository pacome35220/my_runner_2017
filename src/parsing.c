/*
** EPITECH PROJECT, 2017
** parsing
** File description:
** parsing
*/

#include <stdlib.h>
#include <stdio.h>
#include "proto.h"

int get_number(char *line, int *i)
{
	int nb = 0;

	while (line[*i] < '0' || line[*i] > '9')
		(*i)++;
	while (line[*i] >= '0' && line[*i] <= '9') {
		nb = (nb * 10) + line[*i] - '0';
		(*i)++;
	}
	return (nb);
}

int my_strline(char *str)
{
	int i = 0;

	while (str[i] != '\n')
		i++;
	return (i);
}

setting_t parsing(FILE *file)
{
	int index = 0;
	size_t len = 0;
	char *line = NULL;
	char *file_content = NULL;
	setting_t settings;

	while (getline(&line, &len, file) != -1)
		file_content = concat(file_content, line);
	settings.level = get_number(file_content, &index);
	settings.save_level = settings.level;
	index = my_strline(file_content);
	for (int i = 0; i < 5; i++) {
		settings.pipe_pos[i] = get_number(file_content, &index);
		settings.gap[i] = get_number(file_content, &index);
	}
	free(line);
	free(file_content);
	return (settings);
}
