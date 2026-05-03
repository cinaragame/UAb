#include <stdio.h>
#include "validate.h"
#include "io.h"

int VALIDATE_email(char* email, int max_email_size)
{
	int at_counter = 0;
	int at_position = 0;
	int dot_counter = 0;
	int last_dot_position = 0;
	int actual_email_size = 0;

	if(email == NULL)
		return 0;
	//checks for size 0 string
	if(*email == '\0' || *email == '\n')
		return 0;
	for(int i = 0; i < max_email_size; i++)
	{	
		//checks for invalid end of input (no prior '\n', too long input)
		if(email[i] == '\0')
			break;
		//checks for valid end of input ('\n')
		else if(email[i] == '\n')
		{
			actual_email_size = i;
			break;
		}

		if(email[i] == '@')
		{
			at_counter++;
			at_position = i;
		}
		else if(email[i] == '.')
		{
			dot_counter++;
			last_dot_position = i;
		}
	}
	//checks for too long (unchanged) email length
	if(actual_email_size == 0)
	{
		IO_clean_stdin_buffer();
		return 0;
	}
	//checks for exactly one '@' and at least one '.'
	if(at_counter != 1 || dot_counter < 1)
		return 0;
	//checks for at least one char between '@' and '.'
	if(last_dot_position <= at_position + 1)
		return 0;
	//checks for '@' in the beginning
	if(at_position == 0)
		return 0;
	return 1; //all good
}

int VALIDATE_phone(char *phone, int max_phone_size)
{
	int actual_phone_length = 0;
	int not_number_counter = 0;
	if(phone == NULL)
		return 0;
	//checks for size 0 string
	if(*phone == '\0' || *phone == '\n')
		return 0;
	for(int i = 0; i < max_phone_size; i++)
	{
		//checks for invalid end of input (no prior '\n', too long input)
		if(phone[i] == '\0')
			break;
		//checks for valid end of input ('\n')
		if(phone[i] == '\n')
		{
			actual_phone_length = i;
			break;
		}

		if(i == 0 && phone[i] == '+')
			continue;
		if(phone[i] < '0' || phone[i] > '9')
			not_number_counter++;
	}
	//checks for too long (unchanged) phone length
	if(actual_phone_length == 0)
	{
		IO_clean_stdin_buffer();
		return 0;
	}
	if(not_number_counter != 0)
		return 0;
	return 1;
}
