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
char *flagscpy = malloc(200);
strcpy(flagscpy, flags[0]);
rem_newln(buffer);

printf("%s\n", buffer);
flagscpy = strcat(flagscpy, buffer);

if ((execve(flagscpy, flags, NULL)) == -1)
	perror("Cannot find command");

free(flagscpy);
}
