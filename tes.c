#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(void)
{
	char *linp;
	char *line[10];
	char *peace;
	char p[100];
	int stat;
	pid_t child;
	size_t len = 20;

	linp = malloc(sizeof(char) * len);
	printf("before creating child process \n");
	child = fork();
	printf("afret creating\n");
	while (child > 1)
	{
		wait(&stat);
		printf("\ncreating a new child\n");
		child = fork();
	}
	printf("printing before se\n");
	int j = 0;
	while (j < 10)
        {
                printf("%s", line[j]);
                j++;
        }
	printf("#cisfun$ ");

	getline(&linp, &len, stdin);
	peace = strtok(linp, " ");
	int i = 0;
	while (peace)
	{
		line[i] = peace;
		peace = strtok(NULL, " ");
		i++;
	}
	//strcat(p, "/bin/");
	//strcat(p, line[0]);
	//line[0] = p;
	j = 0;
	while (j < 10)
	{
		printf("%s", line[j]);
		j++;
	}
	printf("excute\n");
	if (execve(line[0], line, NULL) == -1)
		printf("didnt work\n");
	printf("you entered %swith a length of %lu\n", linp, len);

	free(linp);
}
