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
char *buffer = NULL, *cmdpath;
size_t charnum = 0;
char **cmd = NULL, **tokdirs = NULL;
pid_t pid;
while (1)
{
	write(STDOUT_FILENO, "$ ", 2);
	readrtn = getline(&buffer, &charnum, stdin);
	if (readrtn == -1)
		break;
	if (strcmp(buffer, "\n") == 0)
		continue;
	cmd = stringparse(buffer);
	if (strcmp(cmd[0], "exit") == 0)
		exithandling(cmd, buffer);
	else
	cmdpath = get_path_command(cmd, tokdirs);
	if (!(access(cmdpath, F_OK) == 0))
		perror("command not found");
	else
	{
		pid = fork();
		if (pid == -1)
		{
			perror("Fork failed");
			return (-1);
		}
		else if (pid == 0)
			execute(cmdpath, cmd);
		else
			wait(NULL);
	}
	if (cmd != NULL)
	{
		for (i = 0; cmd[i] != NULL; i++)
			free(cmd[i]);
		free(cmd);
	}
}
free(buffer);
return (0);
}
