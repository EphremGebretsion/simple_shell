#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int ac, char **av, char **env)
{
	char *line;
	char *line_array[2];
	size_t line_size;
	ssize_t len;
	int i = 0;

	while (1)
	{
		printf("#cisfun$ ");
		len = getline(&line, &line_size, stdin);
		
		if (len != -1)
		{
			line_array[0] = strtok(line, "\n");
			printf("fir %s \n", line_array[0]);
			printf("sec %s \n", line_array[1]);
			if (execve(line_array[0], line_array, env) == -1)
				printf("./shell: No such file or directory\n");
			free(line);
		}
	}
}
