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
	int stat = 0;

	if (!prompt)
	{
		while (stat == 0)
		{
			stat = shell_exec(envi, prog, 0);
		}
	}
	else
	{
		while (stat == 0)
			stat = shell_exec(envi, prog, 1);
		printf("\n");
	}
	return (0);

}
/**
 * exe -executes a command
 * @comand: the command
 * @envi: the environment
 * @prog: program in use
 * Return: returns the exit stat
 */
int exe(char **comand, char **envi, char *prog)
{
	pid_t child;
	int stat;

	child = fork();
	if (child == 0)
	{
		if (execve(comand[0], comand, envi) == -1)
		{
			perror((const char *)prog);
			exit(2);
		}
		exit(0);
	}
	wait(&stat);
	if (stat)
		return (-1);
	return (0);
}
/**
 * shell_exec - excutes the command on child process
 * @envi: environment to use
 * @prog: the program name
 * @prompt: enable or desable prompt
 * Return: exit status of excution
 */
int shell_exec(char **envi, char *prog, int prompt)
{
	size_t line_size = 20;
	char *line = malloc(sizeof(char) * line_size);
	char *line_array[] = {NULL, NULL};
	ssize_t len;
	int wait_status;
	pid_t child;

	child = fork();
	if (!child)
	{
		if (prompt)
		{
			printf("$ ");
			len = getline(&line, &line_size, stdin);
			line_array[0] = strtok(line, "\n");
			if (len == -1)
				exit(2);
			exe(line_array, envi, prog);
		}
		else
		{
			len = getline(&line, &line_size, stdin);
			while (len != -1)
			{
				line_array[0] = strtok(line, "\n");
				exe(line_array, envi, prog);
				len = getline(&line, &line_size, stdin);
			}
			exit(2);
		}
		exit(0);
	}
	free(line);
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
		shell(env, 1, av[0]);
	else
		shell(env, 0, av[0]);
	return (0);
}
