#include "shell.h"

/**
  *cli_arg - function that parses and executes commands from a file
  *
  *@argv: pointer to command line args
  *
  *Return: 0 on success
  */

int cli_arg(char **argv)
{
	FILE *filename = fopen(argv[1], "r");
	char *buff = NULL, **cmd = NULL, **tokdirs = NULL, *cmdpath;

	buff = malloc(1024);
	if (filename == NULL)
	{
		perror("Could not open file");
		return (-1);
	}

	while (fgets(buff, sizeof(buff), filename) != NULL)
	{
		buff[strcspn(buff, "\n")] = '\0';

		cmd = stringparse(buff);
		cmdpath = get_path_command(cmd, tokdirs);
		execute(cmdpath, cmd);

		free(cmd);
		free(cmdpath);
	}
	free(buff);
	fclose(filename);
	return (0);
}
