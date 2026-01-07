#include <stdio.h>

#define MAXSTR 1024

int main(int argc, char **argv)
{
	FILE *f;
	char str[MAXSTR], *pt, c;
	int count = 0, line = 1;

	/*if(argc <= 1)
	{
		printf("Utilização: more <ficheiro>\n");
		return 1;
	}*/

	f = fopen(argv[1], "r");

	if(f == NULL)
		return 1;
	
	while(fread(&c, sizeof(c), 1, stdin) != 0)
	{
		if(count == 0)		//prints number of new line
		{
			printf("%3d:", line);
			line++;
		}
		if(count%75 == 0 && count != 0)	//breaks existing line if more than 75 chars
		{
			fwrite("\n    ", sizeof(char), 5, stdout);
		}
		fwrite(&c, sizeof(c), 1, stdout);
		count++;
		if(c == '\n')
			count = 0;		//reset character counter with new line
	}

	fclose(f);
	return 0;
}
