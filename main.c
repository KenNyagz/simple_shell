#include "shell.h"

/**
*main - entry point
*
*
*Return: 0 -success
*/

int main(void)
{
int readrtn, i = 0;
char *buffer = NULL, *flag = NULL;
size_t charnum = 0;
char **cmd = NULL;
char *cmdpath;

while (1)
{
	write(STDOUT_FILENO, "$ ", 2);
	readrtn = getline(&buffer, &charnum, stdin);
	if (readrtn == -1)
		break;
	if (strcmp(buffer, "\n") == 0)
		continue;

	cmd = stringparse(buffer);
	cmdpath = get_path_command(cmd);
	execute(cmdpath, cmd);

	if (cmd != NULL)
	{
		for (i = 0; cmd[i] != NULL; i++)
			free(cmd[i]);
		free(cmd);
	}

}
free(flag);
free(buffer);
return (0);
}
