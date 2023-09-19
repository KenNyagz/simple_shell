#include "shell.h"

/**
*
*
*
*
*/

/*void checkbuiltins(char **cmd)
{
int i = 0;

builtin builtin_arr[] = {

{"cd", &changedir},
{"printenv", &_printenv},
{"env", &_printenv},
{"setenv", &_setenv},
{"unsetenv", &_unsetenv}
};

cmd[strlen(cmd) - 1] = '\0';

	for (i = 0; i < 5; i++)
	{
		if (strncmp(builtin_arr[i].str, cmd, strlen(cmd)) == 0)
			builtin_arr[i].func(cmd);
		else perror("not found");
	}
}

int main (void)
{
char *buffer = NULL;
size_t n = 0;

while(1)
{
printf("$ ");
if(getline(&buffer, &n, stdin) == -1)
	break;
checkbuiltins(buffer);
}

<<<<<<< HEAD
free(buffer);
return (0);
}
=======
}*/

