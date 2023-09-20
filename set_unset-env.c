#include "shell.h"

/**
*_setenv - sets anew or replaces an environment variable
*@buf: string from standard input
*Return: Void
*/


void _setenv(char *buf)
{
int i = 0;
char *tkn = NULL;
char *var_arr[3] = {NULL, NULL, NULL};

	tkn = strtok(buf, " ");
	while (tkn != NULL)
	{
		var_arr[i] = malloc(strlen(tkn) + 1);
		if (var_arr[i] == NULL)
			perror("Malloc fail");
		strcpy(var_arr[i], tkn);
		tkn = strtok(NULL, " ");
		i++;
	}
	if ((setenv(var_arr[1], var_arr[2], 1) != 0))
		fprintf(stderr, "Unable to set environment");
	/*
	*for (i = 0; environ[i] != NULL; i++)
	*{
	*	printf("%s\n", environ[i]);
	*}
	*printf("\n");
	*/

free(var_arr[0]);
free(var_arr[1]);
free(var_arr[2]);
}

/**
*_unsetenv -  unsets environment variable
*@buf: inputted string
*Return: Void
*/

void _unsetenv(char *buf)
{
int i = 0;
char *tkn = NULL;
char *var_arr[2] = {NULL, NULL};

	tkn = strtok(buf, " ");
	while (tkn != NULL)
	{
		var_arr[i] = malloc(strlen(tkn) + 1);
		if (var_arr[i] == NULL)
			perror("Malloc fail");
		strcpy(var_arr[i], tkn);
		tkn = strtok(NULL, " ");
		i++;
	}
	if ((unsetenv(var_arr[1])) != 0)
		perror("Could not unset variable");

free(var_arr[0]);
free(var_arr[1]);
}

/**
*_printenv - prints environment
*@buf: input string
*
*Return: void
*/

void _printenv(char *buf)
{
int i = 0;
	if ((strcmp(buf, "printenv") == 0) || (strcmp(buf, "env") == 0))
		for (i = 0; environ[i] != NULL ; i++)
		{
			write(STDOUT_FILENO, environ[i], strlen(environ[i]));
			write(1, "\n", 1);
		}
}
