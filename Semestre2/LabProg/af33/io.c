#include "io.h"
#include <stdio.h>

void IO_clean_stdin_buffer()
{
	char c;
	while(1)
	{
		c = getchar();
		if(c == '\n')
			break;
	}
}
