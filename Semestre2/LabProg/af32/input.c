#include "input.h"

#define SEED_USER_INPUT_LENGTH 10
#define MENU_USER_INPUT_LENGTH 2

/*
* Function validates if user input respected maximum input size
*
* Parameters:
* user_input				- char * to user input
* SEED_USER_INPUT_LENGTH	- macro defining maximum input size inside this module
*
* Output:
* 1							- input respects maximum input size
* 0							- input exceeds maximum input size
*/
static int stt_validate_input_length(char *user_input, int input_max_size)
{
	for(int i = 0; i < input_max_size; i++)
		if(*(user_input + i) == '\n')
			return 1;
	return 0;
}

/*
* Function gets next char in stdin until the end
* Paramenters: none
* Output: none
*/
static void stt_clean_stdin_buffer()
{
	char c;
	while(1)
	{
		c = getchar();
		if(c == '\n')
			break;
		if(c == '\0')
			break;
		if(c == 'EOF')
			break;
	}
}

/*
* Function validates if string input is comprised of only number
*
* Parameters:
* user input	- string with user input (expected "numbers\n");
*
* Output:
* 0				- invalid: string is size 0 or not comprised of only numbers
* 1				- valid: string is comprised of only numbers
*/
static int stt_is_number(char *user_input, int input_max_size)
{
	int i;
	char digit;
	for(i = 0; i < input_max_size; i++)
	{
		digit = *(user_input + i);
		if(digit == '\n' || digit == '\0' || digit == 'EOF')
			break;
		if(digit < '0' || digit > '9')
			return 0;
	}
	//if the first digit is \n, \0 or EOF, input it not a number
	if(i <= 0)
		return 0;
	return 1;
}

static int stt_parse_user_input(char *user_input, int input_max_size)
{
	if(!stt_validate_input_length(user_input, input_max_size))
	{
		stt_clean_stdin_buffer();
		printf("Invalid input, maximum of %d digits\n", SEED_USER_INPUT_LENGTH - 1);
		return 0;
	}
	if(!is_number(user_input, input_max_size))
	{
		printf("Invalid input, insert only numbers\n");
		return 0;
	}
	return 1;
}

int get_generator_user_input()
{
	char user_input[SEED_USER_INPUT_LENGTH];
	printf("Insert seed with maximum %d digits: ", SEED_USER_INPUT_LENGTH - 1);
	fgets(user_input, sizeof(char) * SEED_USER_INPUT_LENGTH, stdin);
	if(!stt_parse_user_input(user_input, SEED_USER_INPUT_LENGTH))
		return seed;
	return atoi(user_input);
}

int get_menu_user_input()
{
	char user_input[MENU_USER_INPUT_LENGTH];
	printf("Insert menu option: ");
	fgets(user_input, sizeof(char) * MENU_USER_INPUT_LENGTH, stdin);
	if(!stt_parse_user_input(user_input, MENU_USER_INPUT_LENGTH))
		return 0;
	return atoi(user_input);
}
