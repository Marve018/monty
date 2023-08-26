#include "monty.h"

/**
 * _splitline - split the line into tokens
 * @line: string read by getline function
 *
 * Return: Array of tokens on success, NULL on failure
 *
 */
char **_splitline(char *line)
{
	int buffer_size = 1024;
	int i;
	char **tokens = NULL;
	char *token = NULL;

	tokens = malloc(sizeof(char *) * buffer_size);
	if (!tokens)
		exit(1);
	token = strtok(line, DELIMS);
	if (token == NULL || *token == ' ' || *token == '\n' || *token == '#')
	{
		free(tokens);
		return (NULL);
	}
	for (i = 0; token != NULL; i++)
	{
		tokens[i] = token;
		token = strtok(NULL, DELIMS);
	}
	tokens[i] = NULL;
	return (tokens);
}
