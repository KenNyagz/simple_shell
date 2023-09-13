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
char *cmdpath, **cmd = NULL, **tokdirs = NULL, *buffer = NULL;
size_t charnum = 0;
pid_t pid;
while (1)
{
	write(STDOUT_FILENO, "$ ", 2);
	readrtn = getline(&buffer, &charnum, stdin);
	if (readrtn == -1)
		break;
	if ((strcmp(buffer, "\n") == 0) || (buffer[0]  == '#'))
		continue;

	new_buffer(&buffer);
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
