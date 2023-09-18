#include "shell.h"

/**
  *multi_cmd - parses the string for multiple commands
  *@buffer: string to be parsed
  *Return: array of commands
  */

char **multi_cmd(char *buffer)
{
	char *token = NULL, *buffercpy = NULL, **cmdsarr = NULL, *tokencp = NULL;
	char *delimita = ";";
	int tokencnt = 0, i = 0, j = 0;

	buffercpy = malloc(strlen(buffer) * sizeof(char) + 1);

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
	cmdsarr = malloc(sizeof(char *) * (tokencnt + 1));
	tokencp = strtok(buffercpy, delimita);
	while (tokencp != NULL)
	{
		cmdsarr[i] = strdup(tokencp);	
		if (cmdsarr[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(cmdsarr[j]);
			free(cmdsarr);
			free(buffercpy);
			return (NULL);
		}
		tokencp = strtok(NULL, delimita);
		i++;
	}
	cmdsarr[i] = NULL;
	free(buffercpy);
	return (cmdsarr);
}
