#include "shell.h"

/**
  *checkbuiltins - checks for builtin commands
  *@buf: Input string
  *Return: nothing
  */

void checkbuiltins(char *buf)
{
	buf[strlen(buf) - 1] = '\0';
	if (strncmp(buf, "cd", 2) == 0)
		changedir(buf);
	else if (strncmp(buf, "setenv", 6) == 0)
		_setenv(buf);
	else if (strncmp(buf, "unsetenv", 8) == 0)
		_unsetenv(buf);
	return;
}
