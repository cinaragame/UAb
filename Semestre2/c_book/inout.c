#include <stdio.h>

/*
	Writes one character onscreen using putchar
*/
int main ()
{
	int c;
	char d;
	int control = 0;

	printf("---INT TESTS---\n");

	printf("\nTest char = 65\n");
	c = 65;
	printf("putchar: ");
	control = putchar(c);
	printf("\nprintf: %d\n", control);

	printf("\nTest char = -65\n");
	c = -65;
	printf("putchar: ");
	control = putchar(c);
	printf("\nprintf: %d\n", control);

	printf("\nTest char = EOF\n");
	c = EOF;
	printf("putchar: ");
	control = putchar(c);
	printf("\nprintf: %d\n", control);

	printf("\nTest char = 255\n");
	c = 255;
	printf("putchar: ");
	control = putchar(c);
	printf("\nprintf: %d\n", control);

	printf("---CHAR TESTS---\n");

	printf("\nTest char = 65\n");
	d = 65;
	printf("putchar: ");
	control = putchar(d);
	printf("\nprintf: %d\n", control);

	printf("\nTest char = -65\n");
	d = -65;
	printf("putchar: ");
	control = putchar(d);
	printf("\nprintf: %d\n", control);

	printf("\nTest char = EOF\n");
	d = EOF;
	printf("putchar: ");
	control = putchar(d);
	printf("\nprintf: %d\n", control);

	printf("\nTest char = 255\n");
	d = 255;
	printf("putchar: ");
	control = putchar(d);
	printf("\nprintf: %d\n", control);
}
