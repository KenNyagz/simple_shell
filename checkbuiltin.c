#include "shell.h"

/**
*
*
*
*
*/

void checkbuiltins(char **cmd)
{

builtin builtin_arr[]{
{"exit", (*exithandling)(char **cmd, char *buffer)},
{"cd", (*changedir)(char *buf)};
{"printenv", 


}


}
