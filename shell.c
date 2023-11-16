#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include "main.h"

/**
 * shell - executes our shell by looping
 * @envi: accepts environment form main for use
 * @prompt: used to choose (terminal or pipline) mode
 * @prog: the program name
 * Return: returns the exit status
 */
int shell(char **envi, int prompt, char *prog)
{
	ssize_t len;
	size_t line_size = 20;
	char *line = malloc(sizeof(char) * line_size);
	char *line_array[] = {NULL, NULL};

	if (!prompt)
	{
		printf("in prompt\n");
		len = getline(&line, &line_size, stdin);
		while (len != -1)
		{
			line_array[0] = strtok(line, "\n");
			shell_exec(line_array, envi, prog);
			len = getline(&line, &line_size, stdin);
		}
	}
	else
	{
		printf("in pipe\n");
		while (1)
		{
			printf("$ ");
			len = getline(&line, &line_size, stdin);
			if (len != -1)
			{
				printf("ggg\n");
				line_array[0] = strtok(line, "\n");
				shell_exec(line_array, envi, prog);
			}
			else
			{
				printf("end foind\n");
				return (1);
			}
		}
	}

}

/**
 * shell_exec - excutes the command on child process
 * @com: command being excuted
 * @envi: environment to use
 * @prog: the program name
 * Return: exit status of excution
 */
int shell_exec(char **com, char **envi, char *prog)
{
	int wait_status;
	pid_t child;

	child = fork();
	if (!child)
	{
		if (execve(com[0], com, envi) == -1)
			perror((const char *)
	}
	wait(&wait_status);

	return (wait_status);
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
	if (isatty(0))
	{
		printf("ppp\n");
		shell(env, 1, av[0]);
	}
	else
	{
		printf("nnn\n");
		shell(env, 0, av[0]);
	}
	return (0);
}
