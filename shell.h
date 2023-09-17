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

extern char **environ;

void execute(char *cmdpath, char **cmd);
char *rem_newln(char *str);
int execve(const char *pathname, char *const argv[], char *const envp[]);
char **stringparse(char *buffer);
char *dirconcat(char *str_a, char *str_b);
int access(const char *pathname, int mode);
int exithandling(char **cmd, char *buffer);
char **get_tok_path(void);
char *get_path_command(char **cmd, char **tokdirs);
void changedir(char *buf);
void new_buffer(char **buffer);
void variablerep(char *buf);

#endif
