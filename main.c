#include "shell.h"

/**
*main - entry point
*
*
*Return: 0 -success
*/

int main(void)
{
int readrtn;
char *buffer = NULL;
size_t charnum = 0;

while (1)
{
	write(STDOUT_FILENO, "$ ", 2);
	readrtn = getline(&buffer, &charnum, stdin);
	if (readrtn == -1)
		break;
	if (strcmp(buffer, "\n") == 0)
		continue;

	execute(buffer);

}

free(buffer);
return (0);
}
