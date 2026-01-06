#include <stdio.h>

#define MAXSTR 1024

int main(int argc, char **argv)
{
	FILE *f;
	char str[MAXSTR], *pt, c;
	int count = 0;

	if(argc <= 1)
	{
		printf("Utilização: more <ficheiro>\n");
		return 1;
	}

	f = fopen(argv[1], "rb");

	if(f == NULL)
		return 1;
	
	while(fread(&c, sizeof(c), 1, f) != 0)
	{
		fwrite(&c, sizeof(c), 1, stdout);
	}

	fclose(f);
	return 0;
}
