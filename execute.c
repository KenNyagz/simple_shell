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

void execute(char *buffer)
{
char *flags[] = {"/bin/", NULL};
char *flagscpy;
rem_newln(buffer);

flagscpy = malloc((strlen(flags[0]) + strlen(buffer)) * sizeof(char) + 1);
strcpy(flagscpy, flags[0]);
flagscpy = strcat(flagscpy, buffer);

if ((execve(flagscpy, flags, NULL)) == -1)
	perror("Cannot find command");

free(flagscpy);
}
