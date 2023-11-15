#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include "main.h"

/**
 * main - excutes our simple shell
 * @ac: number of arguments passed
 * @av: array of arguments
 * @env: our environment variable
 * Return: returns 0 on sucess
 */
int main(int ac, char **av, char **env)
{
	size_t line_size = 20;
	char *line = malloc(sizeof(char) * line_size);
	char *line_array[] = {NULL, NULL};
	int last_char;
	ssize_t len;
	pid_t child = 1;
	int status;

	(void)ac;
	(void)av;
	while (child != 0)
	{
		child = fork();
		wait(&status);
	}

	if (child == 0)
	{
		printf("#cisfun$ ");
		len = getline(&line, &line_size, stdin);
		if (len != -1)
		{
			last_char = strlen(line);
			if (line[last_char - 1] != 10)
				printf("\n");
			line_array[0] = strtok(line, "\n");
			if (execve(line_array[0], line_array, env) == -1)
				printf("./shell: No such file or directory\n");
		}
		else
			printf("\n");

		free(line);
	}
	return (0);
}
