#include "monty.h"
/**
 * wrapper - Function that verifies if the command and the
 * arguments are valid, if so it returns the integer of push converted.
 * @stack: Top of the list
 * @line: number of read line
 * @chk_strings: parsed strings
 *
 * Return: Integer of chk_strings converted if success and EXIT_FAILURE
 * if the number doesn't exist and returns 1 if is another function
 */
int wrapper(unsigned int line, char **chk_strings, stack_t **stack)
{
	if (strcmp(chk_strings[0], "push") == 0)
	{
		if (isnumber(chk_strings[1]) == 1)
			glob_vars.glob_int = atoi(chk_strings[1]);
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line);
			free_head(*stack);
			free(chk_strings);
			exit(EXIT_FAILURE);
		}

	}

	get_function(chk_strings[0], line)(stack, line);

	return (0);
}
