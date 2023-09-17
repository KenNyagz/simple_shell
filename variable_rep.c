#include "shell.h"

/**
*variablerep - replaces/expands sys variables
*@buf: string from input
*Return: void
*/

void variablerep(char *buf)
{
int lst_ext, ppid, i, envsize = 0;
char *var_rep, *var_rplc;

	buf[strlen(buf) - 1] = '\0';
	if (strncmp(buf, "$?", 2) == 0)
	{
		lst_ext = WEXITSTATUS(system(NULL));
		dprintf(STDOUT_FILENO, "%d\n", lst_ext);
		return;
	}

	else if (strncmp(buf, "$$", 2) == 0)
	{
		ppid = getppid();
		dprintf(STDOUT_FILENO, "%d\n", ppid);
		return;
	}
	else
	{
		var_rep = strchr(buf, '$');
		if (var_rep == NULL)
			return;
		var_rplc = var_rep + 1;
		while (environ[envsize] != NULL)
			envsize++; /*determing the size of environ*/
		for (i = 0; i < envsize; i++)
		{
			if (strncmp(environ[i], var_rplc, strlen(var_rplc)) == 0)
			{
				dprintf(STDOUT_FILENO, "%s\n", environ[i]);
				break;
			}
		}
	}
}

/*
*int main()
*{
*char *buf = NULL;
*size_t n;
*int readrtn;
*while(1)
*{
*printf("$ ");
*readrtn = getline(&buf, &n, stdin);
*if (readrtn == -1)
*{
*	free(buf);
*	break;
*}
*variablerep(buf);
*}
* **free(buf);
*return (0);
*}
*/
