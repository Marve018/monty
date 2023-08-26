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
int wrapper(char **chk_strings, stack_t **stack, unsigned int line)
{
	char *op_code, *arg;

	op_code = strtok(*chk_strings, "\n ");
	if (op_code == NULL)
		return (-1);

	if (strcmp(op_code, "push") == 0)
	{
		arg = strtok(NULL, "\n ");
		if (isnumber(arg) == 1 && arg != NULL)
			glob_vars.glob_int = atoi(arg);
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line);
			/* free_head(*stack); */
			/* free(*chk_strings); */
			exit(EXIT_FAILURE);
		}

	}

	get_function(op_code, line)(stack, line);

	return (0);
}
