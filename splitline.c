#include "monty.h"

/**
 * op_checker - Function to copy
 * @buff: edited variable
 * @_opcode: edited variable
 * @line_number: line
 * Return: always 0
 */
void op_checker(char *buff, char *_opcode, int line_number)
{
	void (*op_f)(stack_t **, unsigned int);
	int signo = 1, j = 0;
	unsigned int int_value = 0;

	op_f = get_function(_opcode);
	if (op_f)
	{
		if (strcmp(_opcode, "push") == 0)
		{
			if (buff == NULL)
				push_err(line_number);
			else if (buff[0] == '-')
			{
				buff = buff + 1;
				signo = (signo * -1);
			}
			while (buff[j])
			{
				if (isdigit(buff[j]) == 0)
					push_err(line_number);
				j++;
			}
			int_value = atoi(buff) * signo;
			op_f(&head, int_value);
		}
		else
			op_f(&head, line_number);
		return;
	}
	unknown_op_error(_opcode, line_number);
}

/**
 * split - split the line into tokens
 * @line: string read by getline function
 * @num: variable
 * Return: none
 *
 **/
void split(char *line, int num)
{
	char *opcode;
	char *buffer;

	opcode = strtok(line, DELIMS);
	buffer = strtok(NULL, DELIMS);

	if (opcode != NULL)
	{
		if (opcode[0] == '#')
			return;
		op_checker(buffer, opcode, num);
	}
}
