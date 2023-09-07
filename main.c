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
char *buffer = NULL, *flag = NULL;
size_t charnum = 0;
char **cmd = NULL;

while (1)
{
	write(STDOUT_FILENO, "$ ", 2);
	readrtn = getline(&buffer, &charnum, stdin);
	if (readrtn == -1)
		break;
	if (strcmp(buffer, "\n") == 0)
		continue;

	cmd = stringparse(buffer);
	printf("%s\n", cmd[0]);
	execute(cmd);

/*	flag = (char*)malloc((strlen(path)) + (strlen(cmd[0])) + 1);
	strcpy(flag, path);
	printf("%s\n", flag);
	strcat(flag, cmd[0]);

	if ((execve(flag, cmd, NULL)) == -1)
		perror("Execution failed, try again");*/

	if (cmd != NULL)
	{
		for (i = 0; cmd[i] != NULL; i++)
			free(cmd[i]);
		free(cmd);
	}

	/*execute(buffer);*/

}
free(flag);
free(buffer);
return (0);
}
