#include "shell.h"

/**
  *stringparse - parses the string
  *@buffer: string to be parsed
  *Return: array of strings
 */ 

char **stringparse(char *buffer)
{
	char *token = NULL, *buffercpy = NULL, **flagsarr = NULL, *tokencp = NULL;
	int tokencnt = 0, i = 0, j = 0;

	rem_newln(buffer);

	buffercpy = malloc(strlen(buffer) * sizeof(char) + 1);

	if (buffercpy == NULL)
	{
		perror("Memory allocation failed");
		return (NULL);
	}

	strcpy(buffercpy, buffer);
	token = strtok(buffer, " ");
	while (token != NULL)
	{
		tokencnt++;
		token = strtok(NULL, " ");
	}

	flagsarr = malloc(sizeof(char *) * (tokencnt + 1));
	tokencp = strtok(buffercpy, " ");
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
		tokencp = strtok(NULL, " ");
		i++;
	}
	flagsarr[i] = NULL;
	free(buffercpy);
	return (flagsarr);
}
