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
pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Fork failed");
		return;
	}
	else if (pid == 0)
	{
		if ((execve(cmdpath, cmd, environ)) == -1)
			perror("Execution failed, try again");
	}
	else
		wait(NULL);

}

/**
*_free - Frees array of command strings
*@cmd: Array containing commands
*Return: Void
*/

void _free(char **cmd)
{
int i;

for (i = 0; cmd[i] != NULL; i++)
	free(cmd[i]);
free(cmd);

}

/**
  *eof - end of file condition
  *
  *@buffer: pointer to input
  *Return: nothing
  */

void eof(char *buffer)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(buffer);
	exit(0);
}

/**
  *prompt_disp - displays prompt
  *
  *Return: Nothing
  */

void prompt_disp(void)
{
	if (isatty(STDIN_FILENO))
	{
		char *prompt = "$ ";

		write(STDOUT_FILENO, prompt, 2);
	}
}
