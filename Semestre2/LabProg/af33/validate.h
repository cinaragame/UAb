#ifndef VALIDATE_H
#define VALIDATE_H

/*
* Function validates email input
*
* Parameters:
* email				- pointer to email string
* max_email_size	- maximum email length with ending character
*
* Outputs:
* 0					- email address is not valid
* 1 				- email address is valid
*/
extern int VALIDATE_email(char *email, int max_email_size);

/*
* Function validates phone input
*
* Parameters:
* phone				- pointer to phone string
* max_phone_size	- maximum phone length with ending character
*
* Outputs:
* 0					- phone number is not valid
* 1 				- phone number is valid
*/
extern int VALIDATE_phone(char *phone, int max_phone_size);

#endif //VALIDATE_H
