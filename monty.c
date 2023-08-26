#include "monty.h"

/**
 * main - Interpreter of the Monty Language
 * @argc: argument count
 * @argv: the list of arguments
 * Return: 1 if passed
 */
int main(int argc, char *argv[])
{
	stack_t *head = NULL;
	char *file_idx;
	FILE *file;
	char file_line[MAX_LINE_LENGTH];
	unsigned int line_num;
	char **op;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_idx = argv[1];
	file = fopen(file_idx, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_idx);
		exit(EXIT_FAILURE);
	}


	line_num = 0;
	while (fgets(file_line, MAX_LINE_LENGTH, file) != NULL)
	{
		op = _splitline(file_line);

		if (op)
		{
			wrapper(op, &head, line_num);
		}

		free(op);
		line_num++;
	}

	fclose(file);
	exit(EXIT_SUCCESS);

	return (EXIT_SUCCESS);
}
