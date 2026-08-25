#include <stdio.h>                                                             
#define IN      1 /* inside blank streak */
#define OUT     0 /* outside blank streak */
#define VALID   1 /* string contains valid chars */
#define INVALID 0 /* string contains only blanks */
#define MAX_LEN 1000


int getLine(char line[], int max_size);
int removeBlanks(char line[]);                                                 

/* reads line from stdin and prints ot witout trailing blanks, tabs, and blank
lines */
int main()                                                                     {
        char line[MAX_LEN];

        while(getLine(line, MAX_LEN))
        {
                if(removeBlanks(line))
                        printf("%s\n", line);
        }
        return 0;
}

/* reads from stdin and stores input in array
 * parameters:  array, maximum array size
 * return:      size of string sttored
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

/* removes trailing blanks and tabs from string
 * parameter: string
 * return: valid string (contains non blank chars) - 1
 * invalid string (contains only blank chars) - 0
 */
int removeBlanks(char line[])
{ int i, new_size; int blank, valid_char;                                                 
        blank = OUT;
        valid_char = INVALID;
        for(i = 0, new_size = 0; line[i] != '\0'; i++)
        {
                if(line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
                { 
						if(blank == IN)
                                continue;                                      
                        if(line[i] == '\t')
                                line[new_size] = ' ';
                        else
                                line[new_size] = line[i];
                        blank = IN;                                            
                }
                else
                {
                        line[new_size] = line[i];
                        blank = OUT;
                        valid_char = VALID;
                }
                        new_size++;
        }
        line[new_size] = '\0';

        return valid_char;
}
