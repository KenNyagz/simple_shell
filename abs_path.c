#include "shell.h"

/**
  *abs_path - checks if command is an absolute path
  *
  *@cmd: pointer to tokenized path
  *@argv: pointer to arguements
  *@buffer: pointer to input string
  */

void abs_path(char **cmd, char **argv, char *buffer)
{
	char *cmdpath = NULL;

	cmdpath = malloc((strlen(cmd[0]) + 1) * sizeof(char));
	if (cmdpath == NULL)
	{
		perror("Memory allocation failed");
		exit(1);
	}
	else
	{
		strcpy(cmdpath, cmd[0]);
		if (!(access(cmdpath, F_OK) == 0))
			dprintf(STDERR_FILENO, "%s: %s: not found\n", argv[0], buffer);
		else
			execute(cmdpath, cmd);
	}
	free(cmdpath);
	if (cmd != NULL)
		_free(cmd);
}
