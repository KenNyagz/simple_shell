#include "shell.h"

/**
  *
  *
  *
  *
  *
  */

char *dirconcat(char *str_a, char *str_b)
{
	char *str_ab;
	int x, y;
	int num;

	x = 0;
	y = 0;

	num = strlen(str_a) + strlen(str_b) + 2;
	str_ab = malloc(sizeof(char) * num);

	if (!str_ab)
	{
		return (NULL);
	}

	while (str_a[x] != '\0')
	{
		str_ab[y] = str_a[x];
		x++;
		y++;
	}

	if (y != 0)
	{
		str_ab[y] = '/';
		y++;
	}
	x = 0;
	while (str_b[x] != '\0')
	{
		str_ab[y] = str_b[x];
		x++;
		y++;
	}
	str_ab[y] = '\0';

	free(str_b);
	return (str_ab);
}
