#include "shell.h"

/**
  *exithandling - handles the exit function
  *
  *@cmd: pointer to tokenized buffer
  *@buffer: pointer to original string (to be freed to seal
  *memory leaks)
  *
  *Return: returns nothing on success and -1 on failure
  */

int exithandling(char **cmd, char *buffer)
{
	int status, i;

	status = 0;
	if (cmd[1] != NULL)
		status = atoi(cmd[1]);
	if (status > 0)
	{
		for (i = 0; cmd[i] != NULL; i++)
			free(cmd[i]);
		free(buffer);
		free(cmd);
	        exit(status);
	}
	if (status == 0)
	{
		for (i = 0; cmd[i] != NULL; i++)
			free(cmd[i]);
		free(buffer);
		free(cmd);
		exit(EXIT_SUCCESS);
	}
	else
	{
		/*fprintf(stderr, "Unallowed entry %d\n", status);*/
		for (i = 0; cmd[i] != NULL; i++)
			free(cmd[i]);
		free(buffer);
		free(cmd);
		return (status);
	}
}
