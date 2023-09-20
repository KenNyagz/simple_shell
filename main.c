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

if (!isatty(STDIN_FILENO))
	perror("Non-interactive mode. Run script to continue");

while (1)
{
	count++;
	write(STDOUT_FILENO, "$ ", 2);
	fflush(stdout);
	readrtn = getline(&buffer, &charnum, stdin);
	if (readrtn == -1)
		break;
	if ((strcmp(buffer, "\n") == 0) || (buffer[0]  == '#'))
		continue;

	new_buffer(&buffer);
	cmd = stringparse(buffer);
	if (strcmp(cmd[0], "exit") == 0)
		exithandling(cmd, buffer, argc, argv);
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
