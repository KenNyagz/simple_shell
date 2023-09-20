#include "shell.h"

/**
*main - entry point
*@argc: number of arguements
*@argv: array conatining arguements
*Return: 0 -success
*/
int main(int argc, char *argv[])
{
int readrtn, count = 0;
char *cmdpath, **cmd = NULL, **tokdirs = NULL, *buffer = NULL;
size_t charnum = 0;

if (!(argc != 0))
	perror("Provide atleast one argument");
while (1)
{
	count++;
	prompt_disp();
	fflush(stdout);
	readrtn = getline(&buffer, &charnum, stdin);
	if (readrtn == EOF)
		eof(buffer);
	if (readrtn == -1)
	{
		free(buffer);
		exit(EXIT_FAILURE);
	}
	if (strcmp(buffer, "\n") == 0)
		continue;

	rem_newln(buffer);
	cmd = stringparse(buffer);
	if (strcmp(cmd[0], "exit") == 0)
		exithandling(cmd, buffer);
	else
		cmdpath = get_path_command(cmd, tokdirs);
	if (!(access(cmdpath, F_OK) == 0))
		dprintf(STDOUT_FILENO, "%s: %d: %s: not found\n", argv[0], count, buffer);
	else
		execute(cmdpath, cmd);

	if (cmd != NULL)
		_free(cmd);
}
free(buffer);
return (0);
}
