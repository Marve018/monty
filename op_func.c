#include "monty.h"

/**
 * push - Pushes a value to a stack_t linked list.
 * @stack: A pointer to the top
 * @value: line number.
 */
void push(stack_t **stack, unsigned int value)
{
	stack_t *new_node;
	stack_t *present = *stack;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->next = *stack;
	new_node->prev = NULL;

	if (present != NULL)
	{
		present->prev = new_node;
	}
	head = new_node;
}

/**
 * pall - Prints the values all stack.
 * @stack: A pointer to the top
 * @value: line number.
 */
void pall(stack_t **stack, unsigned int value)
{
	stack_t *tmp;

	(void)value;

	tmp = *stack;
	if (*stack != NULL)
	{
		while (tmp != NULL)
		{
			printf("%d\n", tmp->n);
			tmp = tmp->prev;
		}
	}
	else
		exit(EXIT_FAILURE);
}
