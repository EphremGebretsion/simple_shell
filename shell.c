#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include "main.h"

/**
 * shell - excutes our shell program prompt, getcommand, excute
 * @envi: acepts environment from main and use it
 * @prog: the name of the program used to excute
 * @prompt: enables(1) or desables(0) prompt 
 */

void shell(char **envi, char *prog, int prompt)
{
	size_t line_size = 20;
	char *line = malloc(sizeof(char) * line_size);
	char *line_array[] = {NULL, NULL};
	ssize_t len;

	if (prompt)
		printf("$ ");
	len = getline(&line, &line_size, stdin);
	while(len != -1)
	{
		line_array[0] = strtok(line, "\n");
		if (execve(line_array[0], line_array, envi) == -1)
			perror((const char *)prog);
		if (prompt)
			break;
		len = getline(&line, &line_size, stdin);
	}
	if (len == -1 && prompt)
	{
		printf("\n");
		exit(2);
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
	pid_t child = 1;
	int wait_status;

	(void)ac;
	if (isatty(0))
	{
		while (child)
		{
			child = fork();
			wait(&wait_status);
			if (child)
			{
				if (wait_status)
					return (0);
			}
			if (!child)
				shell(env, av[0], 1);
		}
	}
	else
		shell(env, av[0], 0);
	return (0);
}
