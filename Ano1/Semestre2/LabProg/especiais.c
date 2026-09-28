#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
	int i = 0;
	int j = 1;

	printf("argc = %i\n", argc);
	while (j < argc)
	{
		printf("argument = %s\n", (argv[j]));
		i = 0;
		while (i < strlen(argv[j]))
		{
			printf("%c %i\n", argv[j][i], (int)argv[j][i]);
			i++;
		}
		j++;
	}
	
}
