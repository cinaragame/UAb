#include <stdio.h>

/*
	Prints value of EOF
	Shows that ((c = getchar()) != EOF) & (c = getchar() != EOF) are different
*/
int main ()
{
	int c;

	c = EOF;
	printf("Value of EOF is: %d\n", c);

	//Testing precedence of != and ==
	printf("Type something and have it written back to you (or not)!\n");
	c = (getchar() != EOF);
	printf("%d\n", c);
	//Faz som de "blip"
	c = 7;
	putchar(c);
}
