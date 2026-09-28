#include <stdio.h>

int validate(char* argv)
{
	int counter = 0;
	int i;

	for(i = 0; argv[i] != '\0'; i++)
	{
		if(argv[i] != 'I' && argv[i] != 'V' && argv[i] != 'X'
			&& argv[i] != 'L' && argv[i] != 'C' && argv[i] != 'D'
			&& argv[i] != 'M')
			counter++;
	}

	return counter;
}

int convert(char* romano)
{
	int arabe = 0;
	int i = 0;
	
	while(romano[i] != '\0')
	{
		if(romano[i] == 'M')
		{
			arabe += 1000;
			i++;
		}

		else if(romano[i] == 'D')
		{
			arabe += 500;
			i++;
		}

		else if(romano[i] == 'C')
		{
			if(romano[i+1] != '\0' && romano[i+1] == 'M')
			{
				arabe += 900;
				i += 2;
			}
			else if(romano[i+1] != '\0' && romano[i+1] == 'D')
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
		else if(romano[i] == 'L')
		{
			arabe += 50;
			i++;
		}
		else if(romano[i] == 'X')
		{
			if(romano[i+1] != '\0' && romano[i+1] == 'L')
			{
				arabe += 40;
				i += 2;
			}
			else if(romano[i+1] != '\0' && romano[i+1] == 'C')
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
		else if(romano[i] == 'V')
		{
			arabe += 5;
			i++;
		}
		else if(romano[i] == 'I')
		{
			if(romano[i+1] != '\0' && romano[i+1] == 'X')
			{
				arabe += 9;
				i += 2;
			}
			
			else if(romano[i+1] != '\0' && romano[i+1] == 'V')
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

	if(validate(argv[1]) > 0)
	{
		printf("Insert only roman numbers\n");
		return 1;
	}

	//Assume person inserted number right and in a logical manner 
	arabe = convert(argv[1]);
	
	if(arabe == 0)
	{
		printf("usage example: /.NumerosRomanos XIX\n");
		return 1;
	}
	printf("%s = %i\n", argv[1], arabe);
}
