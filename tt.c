#include <stdio.h>

int main(void)
{
	char *p = NULL;
	int size = 20;
	char *str[20] = ["hello"];


	printf("my str is %s\n", p);

	for (int i = 0; i < size; i++)
        {
                printf("%s\n", str[i]);
        }

}
