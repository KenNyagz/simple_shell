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
char *var_arr[2] = {NULL, NULL};
	buf[strlen(buf) - 1] = '\0';

	tkn = strtok(buf, " ");
	while (tkn != NULL && (i < 2))
	{
		var_arr[i] = malloc(strlen(tkn) + 1);
		if (var_arr[i] == NULL)
			perror("Malloc fail");
		strcpy(var_arr[i], tkn);
		tkn = strtok(NULL, " ");
		i++;
	}
	if ((setenv(var_arr[0], var_arr[1], 1) != 0))
		fprintf(stderr, "Unable to set environment");
	/*
	*for (i = 0; environ[i] != NULL; i++)
	*{
	*	printf("%s\n", environ[i]);
	*}
	*/
free(var_arr[0]);
free(var_arr[1]);
}

/*
*int main()
*{
*char *buffer = NULL;
*size_t n = 0;
*int rdrtn = 0;
*while(1)
*{
*printf("$ ");
*rdrtn = getline(&buffer, &n, stdin);
*if (rdrtn == -1)
*	break;
*_setenv(buffer);
*}
*free(buffer);
*return (0);
*}
*/

/*--------------*/

/**
*_unsetenv -  unsets environment variable
*@buf: inputted string
*Return: Void
*/

void _unsetenv(char *buf)
{




}
