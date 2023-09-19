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
	char *buff = NULL, **cmd = NULL, **tokdirs = NULL, *cmdpath = NULL;
	int count = 0;

	if (filename == NULL)
	{
		perror("Could not open file");
		return (-1);
	}

	buff = malloc(256);
	while (fgets(buff, sizeof(buff), filename) != NULL)
	{
<<<<<<< HEAD
		/*buff[strlen(buff) - 1] = '\0';
		buff[strlen(buff) - 2] = '\0';*/

=======
		count++;
		buff[strcspn(buff, "\n")] = '\0';
>>>>>>> a9795c8178e12ab57ee9c40cbd6621817a0d14a5
		cmd = stringparse(buff);
		cmdpath = get_path_command(cmd, tokdirs);
		/*if (!(access(cmdpath, F_OK) == 0))*/
	               /* dprintf(STDOUT_FILENO, "%s: %d: %s: not found\n", argv[0], count, buffer);*/
		execute(cmdpath, cmd);

		free(cmd);
		free(cmdpath);
	}
	free(buff);
	fclose(filename);
	return (0);
}
