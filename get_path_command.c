#include "shell.h"

/**
  *get_tok_path - tokenizes the "PATH"
  *
  *Return: pointer to array of tokenized "PATH"
  */
char **get_tok_path(void)
{
	char **tokdirs;
	char *the_path, *the_path2, *tkn, *tkn2, *delimita = ":";
	int i = 0, tkn_count = 0;
	size_t len;

	len = strlen(getenv("PATH"));
	the_path = malloc(len + 1);
	strcpy(the_path, getenv("PATH"));
	the_path2 = strdup(the_path);
	if (the_path2 == NULL)
	{
		perror("Memory allocation failed");
		return (NULL);
	}
	tkn = strtok(the_path, delimita);
	while (tkn != NULL)
	{
		tkn_count++;
		tkn = strtok(NULL, delimita);
	}
	tokdirs = malloc(sizeof(char *) * (tkn_count + 1));
	tkn2 = strtok(the_path2, delimita);
	i = 0;
	while (tkn2 != NULL)
	{
		tokdirs[i] = strdup(tkn2);
		tkn2 = strtok(NULL, delimita);
		i++;
	}
	tokdirs[i] = NULL;
	free(the_path2);
	free(the_path);
	return (tokdirs);
}

/**
  *get_path_command - gets the concatenated command for execve
  *
  *@cmd: pointer to array that holds tokenized input from strparse
  *@tokdirs: pointer to array that holds tokenized "PATH"
  *
  *Return: returns 1st argument for execve
  */

char *get_path_command(char **cmd, char **tokdirs)
{
	char *start_dir;
	int i;
	struct stat _fileinfo;

	tokdirs = get_tok_path();
	start_dir = getcwd(NULL, 0);
	for (i = 0; tokdirs[i] != NULL; i++)
	{
		chdir(tokdirs[i]);
		if (stat(cmd[0], &_fileinfo) == 0)
		{
			cmd[0] = dirconcat(tokdirs[i], cmd[0]);
			break;
		}
	}
	for (i = 0; tokdirs[i] != NULL; i++)
		free(tokdirs[i]);
	chdir(start_dir);
	free(start_dir);
	free(tokdirs[i]);
	free(tokdirs);
	return (cmd[0]);
}
