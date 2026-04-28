#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	srandom(2);
	printf("%lu\n", random());
}
