#include "menu.h"
#include "input.h"
#include "generator.h"

void stt_written_options()
{
	printf("\n----MENU----\n"
		"1 - Generate new random number\n"
		"2 - Print current seed\n"
		"3 - Print current random number\n"
		"4 - Print quantity of random numbers generated in this session\n"
		"5 - Reset program\n"
		"6 - End program\n"
		"7 - Help\n"
			"------------\n\n");
}

void menu()
{
	static int selected_menu_option = 0;
	stt_written_options();
	while(selected_menu_option != 6)
	{
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
				generator_print_generator_counter();
				break;
			case 5:
				printf("Resetting program\n");
				generator_set_program_to_state_zero();
				break;
			case 6:
				printf("Closing program\n");
				break;
			case 7:
				stt_written_options();
				break;
			default:
		}
	}
}
