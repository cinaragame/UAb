#include <stdio.h>

int validate(char** argv)
{
	int counter = 0;
	int i;

	for(i = 0; argv[1][i] != '\0'; i++)
	{
		if(argv[1][i] != 'I' && argv[1][i] != 'V' && argv[1][i] != 'X'
			&& argv[1][i] != 'L' && argv[1][i] != 'C' && argv[1][i] != 'D'
			&& argv[1][i] != 'M')
			counter++;
	}

	return counter;
}

int convert(char** romano)
{
	int arabe = 0;
	int i = 0;
	
	while(romano[1][i] != '\0')
	{
		if(romano[1][i] == 'M')
		{
			arabe += 1000;
			i++;
		}

		else if(romano[1][i] == 'D')
		{
			arabe += 500;
			i++;
		}

		else if(romano[1][i] == 'C')
		{
			if(romano[1][i+1] != '\0' && romano[1][i+1] == 'M')
			{
				arabe += 900;
				i += 2;
			}
			else if(romano[1][i+1] != '\0' && romano[1][i+1] == 'D')
			{
				arabe += 400;
				i += 2;
			}
			else
			{
				arabe += 100;
				i++;
			}
		}
		else if(romano[1][i] == 'L')
		{
			arabe += 50;
			i++;
		}
		else if(romano[1][i] == 'X')
		{
			if(romano[1][i+1] != '\0' && romano[1][i+1] == 'L')
			{
				arabe += 40;
				i += 2;
			}
			else if(romano[1][i+1] != '\0' && romano[1][i+1] == 'C')
			{
				arabe += 90;
				i += 2;
			}
			else
			{
				arabe += 10;
				i++;
			}
		}
		else if(romano[1][i] == 'V')
		{
			arabe += 5;
			i++;
		}
		else if(romano[1][i] == 'I')
		{
			if(romano[1][i+1] != '\0' && romano[1][i+1] == 'X')
			{
				arabe += 9;
				i += 2;
			}
			
			else if(romano[1][i+1] != '\0' && romano[1][i+1] == 'V')
			{
				arabe += 4;
				i += 2;
			}
			else
			{
				arabe++;
				i++;
			}
		}
		else return 0;
	}
	return arabe;
}

int main(int argc, char** argv)
{
	int arabe = 0;

	if(argc != 2)
	{
		printf("usage example: /.NumerosRomanos XIX\n");
		return 1;
	}

	if(validate(argv) > 0)
	{
		printf("Insert only roman numbers\n");
		return 1;
	}

	//Assume person inserted number right and in a logical manner 
	arabe = convert(argv);
	
	if(arabe == 0)
	{
		printf("usage example: /.NumerosRomanos XIX\n");
		return 1;
	}
	printf("%s = %i\n", argv[1], arabe);
}
