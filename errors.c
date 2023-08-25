#include "monty.h"

/**
 * unknown_op_error - Prints unknown instruction error.
 * @opcode: Opcode where error occurred.
 * @lines: Line number where error occured.
 * Return: (EXIT_FAILURE).
 */
int unknown_op_error(char *opcode, unsigned int lines)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
			lines, opcode);
	exit(EXIT_FAILURE);
}

/**
 * push_err - invalid _push arg error.
 * @linenum: Line number in Monty bytecodes file where error occurred.
 * Return: (EXIT_FAILURE).
 */
int push_err(int linenum)
{
	fprintf(stderr, "L%d: usage: push integer\n", linenum);
	exit(EXIT_FAILURE);
}
