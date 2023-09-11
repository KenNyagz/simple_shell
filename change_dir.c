#include "shell.h"

/**
*changedir - changes directory
*@cmd: strings array with cd command and dir name
*Return: void
*
*/

void changedir(char **cmd)
{
char *oldpwd, *newpwd;

oldpwd = getcwd(NULL, 0);
setenv("OLDPWD", oldpwd, 1);

	if (cmd[1] == NULL)
	{
		newpwd = getenv("HOME");
		chdir(newpwd);
	}
	else if (strcmp(cmd[1], "-") == 0)
	{
		newpwd = getenv("OLDPWD");
		chdir(newpwd);
		setenv("PWD",  newpwd, 1);
	}
	else if (chdir(cmd[1]) == 0)
	{
		newpwd = getcwd(NULL, 0);
		setenv("PWD", newpwd, 1);
	}
	else
		perror("Unable to change to directory");

free(oldpwd);
free(newpwd);
}
