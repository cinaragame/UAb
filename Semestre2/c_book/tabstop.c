#include <stdio.h>

#define MAX_LEN 50
#define TAB_STOP 8 /* tab size */

int getLine(char line[], int max_size);
int blanksForTabstop(int position, int tab_size);

int main(void)
{
	char	input[MAX_LEN];		/* arrays for input (with tab) */
	char	output[MAX_LEN];	/* arrays for (with tabs substituted by blanks) */
	int		in_cnt, out_cnt;	/* input and output arrays char counter */	
	int		blanks;				/* blanks needed to substitute tab */
	
	/* while valid line of input */
	while(getLine(input, MAX_LEN))
	{
		in_cnt = out_cnt = 0;
		/* copy input to new string */
		while(out_cnt < MAX_LEN-1 && input[in_cnt] != '\0')
		{
			if(input[in_cnt] == '\t')
			{
				blanks = blanksForTabstop(out_cnt, TAB_STOP);
				while(blanks > 0 && out_cnt < MAX_LEN-1)
				{
					output[out_cnt++] = ' ';	
					blanks--;
				}
				in_cnt++;
			}
			else
			{
				output[out_cnt] = input[in_cnt];
				in_cnt++;
				out_cnt++;
			}
		}
		output[out_cnt] = '\0';
		/* outputs result */
		printf("\n%s\n", output);
	}	
}

/* stores input from stdin in array
 * parameters:	array
 * 				array maximum size
 * return:		size of input
 */
int getLine(char line[], int max_size)
{
	int i, c;

	i = 0;
	while(i < max_size-1 && (c = getchar()) != EOF && c != '\n')
	{
		line[i] = c;
		i++;
	}
	if(c == '\n')
	{
		line[i] = c;
		i++;
	}
	line[i] = '\0';
	return i;
}

/* calculates number of blank spaces to reach next tab stop
 * parameters:	position of tab character in original array
 * 				tab size
 * return:		number of blank spaces
 */
int blanksForTabstop(int position, int tab_size)
{
	int i;

	i = 1;
	while(((position + i) % tab_size) != 0)
		i++;
	
	return i;
}
