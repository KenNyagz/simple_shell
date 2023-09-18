#include "shell.h"

/**
*
*
*
*
*/

void setenv(char **cmd)
{
    char *varname = cmd[1]i;
    char *value = cmd[2];

    int result = setenv(varname, value, 1); /*Overwrite if the variable already exists*/

    if (result != 0) {
        perror("setenv failed");
        return 1;
    }

    else
	    write(xxxxxxx);
    return
}
