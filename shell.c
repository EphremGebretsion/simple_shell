#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include "main.h"

/**
 * shell_loop - used to loop our shell
 * @envi: the environment to use
 * @prog: the program name being excuted
 */
void shell_loop(char **envi, char *prog)
{
	size_t line_size = 20;
	char *line = malloc(sizeof(char) * line_size);
	char *line_array[] = {NULL, NULL};
	ssize_t len;
	int wait_status;
	pid_t child = 1;

	while (child)
	{
		printf("#cisfun$ ");
		len = getline(&line, &line_size, stdin);
		if (len != -1)
		{
			child = fork();
			wait(&wait_status);

			if (!child)
			{
				line_array[0] = strtok(line, "\n");
				if (execve(line_array[0], line_array, envi) == -1)
					perror((const char *)prog);
			}
		}
		else
		{
			printf("\n");
			child = 0;
		}
	}
	free(line);
}

/**
 * main - excutes our simple shell
 * @ac: number of arguments passed
 * @av: array of arguments
 * @env: our environment variable
 * Return: returns 0 on sucess
 */

int main(int ac, char **av, char **env)
{
	(void)ac;
	shell_loop(env, av[0]);
	return (0);
}

