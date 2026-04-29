#include "input.h"
#include "menu.h"

void menu()
{
	static int selected_menu_option = 0;
	while(selected_menu_option != 6)
	{
		printf("----MENU----\n"
			"1 - Generate new random number\n"
			"2 - Print current seed\n"
			"3 - Print current random number\n"
			"4 - Print quantity of random numbers generated in this session\n"
			"5 - Reset program\n"
			"6 - End program\n");
		selected_menu_option = get_menu_user_input();
		switch(selected_menu_option)
		{
			case 1:
				generator_set_new_random_number();
				break;
			case 2:
				generator_print_seed();
				break;
			case 3:
				generator_print_random_number();
				break;
			case 4:
				generator_print_counter();
				break;
			case 5:
				generator_reset_program();
				break;
			case 6:
				printf("Closing program\n");
				break;
			default:
				printf("Invalid option\n");
		}
	}
}
