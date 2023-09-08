#include "shell.h"
/**
*rem_newln - removes newline character and replaces it with Null terminator
*@str: string to be modified
*Return: the Null terminated string
*/
char *rem_newln(char *str)
{
int length = strlen(str);
if (length > 0 && str[length - 1] == '\n')
	str[length - 1] = '\0';

return (str);
}

/**
*execute - executes a fucntion from the path directories
*@buffer: the command string
*Return: void
*/

void execute(char *cmdpath, char **cmd)
{
	/*const char *path = "/bin/";
	char *flag;

	flag = (char*)malloc((strlen(path)) + (strlen(cmd[0])) + 1);
	strcpy(flag, path);

	strcat(flag, cmd[0]);*/

	if ((execve(cmdpath, cmd, NULL)) == -1)
		perror("Execution failed, try again");

/*free(flag);*/
}
