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

char **stringparse(char *buffer);
char *dirconcat(char *str_a, char *str_b);

int exithandling(char **cmd, char *buffer);

char *get_path_command(char **cmd, char **tokdirs);
void changedir(char *buf);
void new_buffer(char **buffer);
void checkbuiltins(char *buf);
void _free(char **cmd);

void eof(char *buffer);
void prompt_disp(void);
void abs_path(char **cmd, char **argv, char *buffer);


int cli_arg(char **argv);
void getlinefail(ssize_t readrtn, char *buffer);


#endif
