#include <stdio.h>
#include "validate.h"

int main(void)
{
	char phone[20];
	char email[30];

	while(1)
	{
	printf("Insert phone number: ");
	fgets(phone, 20, stdin);
	if(!VALIDATE_phone(phone, 20))
		printf("Invalid number\n");
	else
		printf("Valid number\n");

	printf("Insert email: ");
	fgets(email, 30, stdin);
	if(!VALIDATE_email(email, 30))
		printf("Invalid email\n");
	else
		printf("Valid email\n");
	}
}
