#include "generator.h"
#include "input.h"

static int seed;
static unsigned int generator_counter;
static int random_number;

int generator_get_seed()
{
	return seed;
}
static void stt_reset_seed()
{
	seed = 0;
}

static void stt_reset_generator_counter()
{
	generator_counter = 0;
}

static void stt_reset_random_number()
{
	random_number = 0;
}

void generator_set_program_to_state_zero()
{
	stt_reset_seed();
	stt_reset_generator_counter();
	stt_reset_random_number();
}

static void stt_set_seed(int user_seed)
{
	seed = user_seed;
}

static void stt_set_random_number()
{
	int internal_seed = seed; //HERE LIES THE PROBLEM WITH GLOBAL VARIABLES
	random_number = (((internal_seed = internal_seed * 214013L + 2531011L) >> 16) & 0x7fff);
	generator_counter++;
}

void generator_set_new_random_number()
{
	int new_seed;
	new_seed = get_generator_user_input();
	stt_set_seed(new_seed);
	stt_set_random_number();
}

static void stt_print_seed()
{
	if(generator_counter <= 0)
		printf("No number has been generated yet. Standand value:\n");
	printf("Seed: %d\n", seed);
}

static void stt_print_random_number()
{
	if(generator_counter <= 0)
		printf("No number has been generated yet. Standand value:\n");
	printf("Random number: %d\n", random_number);
}

static void stt_print_generator_counter()
{
	if(generator_counter <= 0)
		printf("No number has been generated yet.\n");
	printf("Generator counter: %d\n", generator_counter);
}
void generator_print_seed()
{
	stt_print_seed();
}

void generator_print_random_number()
{
	stt_print_random_number();
}

void generator_print_generator_counter()
{
	stt_print_generator_counter();
}
