#include "shell.h"

/**
  *stringparse - parses the string
  *@buffer: string to be parsed
  *Return: array of strings
 */

char **stringparse(char *buffer)
{
	char *token = NULL, *buffercpy = NULL, **flagsarr = NULL, *tokencp = NULL;
	char *delimita = " \t\n";
	int tokencnt = 0, i = 0, j = 0;

	buffercpy = malloc((strlen(buffer) + 1) * sizeof(char));

	if (buffercpy == NULL)
	{
		perror("Memory allocation failed");
		return (NULL);
	}

	strcpy(buffercpy, buffer);
	token = strtok(buffer, delimita);
	while (token != NULL)
	{
		tokencnt++;
		token = strtok(NULL, delimita);
	}

	flagsarr = malloc(sizeof(char *) * (tokencnt + 1));
	tokencp = strtok(buffercpy, delimita);
	while (tokencp != NULL)
	{
		flagsarr[i] = strdup(tokencp);
		if (flagsarr[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(flagsarr[j]);
			free(flagsarr);
			free(buffercpy);
			return (NULL);
		}
		tokencp = strtok(NULL, delimita);
		i++;
	}
	flagsarr[i] = NULL;
	free(buffercpy);
	return (flagsarr);
}
