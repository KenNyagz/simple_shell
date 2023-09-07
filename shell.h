#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void execute(char **cmd);
char *rem_newln(char *str);
int execve(const char *pathname, char *const argv[], char *const envp[]);
char **stringparse(char *buffer);

#endif
