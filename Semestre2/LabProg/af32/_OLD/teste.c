#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	srandom(100);
	printf("%lu\n", random());
}
