#include <stdio.h>
#include <unistd.h>

int main(void)
{
	printf("enter something: ");
	char *line;
	size_t s;
	getline(&line, &s, stdin);

	printf("you entered %s \n", line);

        int size = 20;
        char *str[20];

        for (int i = 0; i < size; i++)
        {
                printf("%s \n", str[i]);
        }
        printf("test is working ephi huuu\n");
}
