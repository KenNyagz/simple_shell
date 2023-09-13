#include "shell.h"

/**
*main - entry point
*@argc: number of arguements
*@argv: array conatining arguements
*Return: 0 -success
*/
int main(int argc, char *argv[])
{
int readrtn, i = 0, count = 0;
char *cmdpath, **cmd = NULL, **tokdirs = NULL, *buffer = NULL;
size_t charnum = 0;
pid_t pid;

if (!(argc != 0))
	perror("There are 0 arguements. Please provide atleast 1 arguement");
else
if (!isatty(STDIN_FILENO))
	perror("Non-interactive mode. Run script to continue");
else
while (1)
{
	count++;
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
	/*count++;*/
	if (!(access(cmdpath, F_OK) == 0))
		/*perror("command not found");*/
		printf("%s: %d: %s: not found\n", argv[0], count, buffer);
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
