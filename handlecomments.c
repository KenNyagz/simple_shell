#include "shell.h"

/**
  *new_buffer - removes # from string
  *
  *@buffer: pointer to string with #
  *
  *Return: pointer to string before # is encountered
  */

void new_buffer(char **buffer)
{
	size_t len;
	char *rmv_hash, *buff;

	if (!(strncmp(*buffer, "echo", 4) == 0))
	{
		rmv_hash = strchr(*buffer, '#');
		if (rmv_hash != NULL)
		{
			len = strlen(*buffer) - strlen(rmv_hash);
			buff = (char *)malloc(len + 256);

			if (buff != NULL)
			{
				strncpy(buff, *buffer, len);
				buff[len] = '\0';
				free(*buffer);
				*buffer = buff;
			}
		}
	}
}
