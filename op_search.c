#include "monty.h"

/**
 * get_function - search the code with its function.
 * @cmd: The func code.
 * @line_num: line number.
 * Return: function.
 */
void (*get_function(char *cmd, unsigned int line_num))(stack_t**, unsigned int)
{
	unsigned int i = 0;
	instruction_t opcodes[] = {{"push", push}, {"pall", pall},
		{"pint", pint}, {"pop", pop}, {NULL, NULL}
	};

	for (; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(cmd, opcodes[i].opcode) == 0)
		{
			return (opcodes[i].f);
		}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_num, cmd);
	free(cmd);
	exit(EXIT_FAILURE);
}
