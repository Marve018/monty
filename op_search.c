#include "monty.h"

/**
 * get_function - search the code with its function.
 * @command: The func code.
 * Return: function.
 */
void (*get_function(char *command))(stack_t**, unsigned int)
{
	unsigned int i = 0;
	instruction_t opcodes[] = {{"push", push}, {"pall", pall},
		{NULL, NULL}
	};

	for (; opcodes[i].opcode; i++)
	{
		if (strcmp(command, opcodes[i].opcode) == 0)
			return (opcodes[i].f);
	}

	return (NULL);
}
