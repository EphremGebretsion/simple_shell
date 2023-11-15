#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

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
	ssize_t len;
	int i = 0;

	while (1)
	{
		printf("first = %s\nsec = %s\n", line_array[0], line_array[1]);
		printf("#cisfun$ ");
		len = getline(&line, &line_size, stdin);
		if (len != -1)
		{
			printf("no this part \n");
			line_array[0] = strtok(line, "\n");
			printf("this part\n");
			if (execve(line_array[0], line_array, env) == -1)
				printf("./shell: No such file or directory\n");
			free(line);
		}
	}
	return (0);
}
