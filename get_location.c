#include "main.h"

char *get_location(char *command)
{
	char *path, *path_copy, *file_path;
	char *path_token;
	int command_len, directory_len;
	struct stat buffer;

	path = getenv("PATH");
	if (path)
	{
		command_len = strlen(command);
		path_copy = strdup(path);
		path_token = strtok(path_copy,":");

		while (path_token != NULL)
		{
			directory_len = strlen(path_token);
			file_path = malloc(command_len + directory_len + 2);
			file_path = strcpy(file_path, path_token);
			file_path = strcat(path_token, "/");
			file_path = strcat(path_token, command);
			file_path = strcat(path_token, "\0");
			
			if (stat(file_path, &buffer) == 0 )
			{
				free(path_copy);
				return (file_path);
			}
		else
		{
			free(file_path);
			path_token = strtok(NULL, ":");
		}
	
		}	
	free(path_copy);
	if (stat(command, &buffer) == 0)
	{
		return (command);
	}
	return (NULL);
	}

	return (NULL);
}
