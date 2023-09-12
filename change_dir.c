#include "shell.h"

/**
*changedir - changes directory
*@cmd: strings array with cd command and dir name
*Return: void
*
*/

void changedir(char *buf)
{
char *newpwd, *lasttkn = NULL;
char *tkn, *bufcp;
	if (strcmp(buf, "cd") == 0)
	{
		newpwd = getenv("HOME");
		chdir(newpwd);
		setenv("PWD", newpwd, 1);
		return;
	}
	else if (strcmp(buf, "cd -") == 0)
	{
		newpwd = getenv("OLDPWD");
		chdir(newpwd);
		setenv("PWD",  newpwd, 1);
		write(STDOUT_FILENO, newpwd, strlen(newpwd));
		write(STDOUT_FILENO, "\n", 1);
		return;
	}
	bufcp = strdup(buf);
	tkn = strtok(bufcp, " ");
	while (tkn != NULL)
	{
		lasttkn = tkn;
		tkn = strtok(NULL, " ");
	}
	if (chdir(lasttkn) == 0)
	{
		newpwd = malloc(256);
		getcwd(newpwd, 256);
		setenv("PWD", newpwd, 1);
		free(newpwd);
	}
	else
		perror("Cannot change to directory");
free(bufcp);
}
