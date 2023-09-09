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
*@cmdpath: 1st arguement for execve
*@cmd: pointer to array containing arguements to cmdpath
*Return: void
*/

void execute(char *cmdpath, char **cmd)
{

	if ((execve(cmdpath, cmd, NULL)) == -1)
		perror("Execution failed, try again");
}
