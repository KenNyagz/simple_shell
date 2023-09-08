#include "shell.h"

/**
  *
  *
  *
  *
  *
  */

char *get_path_command(char **cmd)
{
	char **tokdirs;
	char *the_path, *the_path2, *tkn, *tkn2, *start_dir, *delimita = ":";
	int i = 0, tkn_count = 0;
	struct stat _fileinfo;
	size_t len;

	len = strlen(getenv("PATH"));
	the_path = malloc(len + 1);
	strcpy(the_path, getenv("PATH"));
	/*printf("%s\n", the_path);*/
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
	/*return tokdirs*/

	start_dir = getcwd(NULL, 0);
	for (i = 0;i < tkn_count; i++)
	{
		chdir(tokdirs[i]);
		if (stat(cmd[0], &_fileinfo) == 0)
		{
			cmd[0] = dirconcat(tokdirs[i], cmd[0]);
			break;
		}
		/*free(tokdirs[i]);*/
	}
	for (i = 0; i < tkn_count; i++)
		free(tokdirs[i]);
	chdir(start_dir);
	free(start_dir);
	free(tokdirs[i]);
	free(tokdirs);
	free(the_path);
	return (cmd[0]);
}
