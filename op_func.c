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
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pint - Prints the top value of a stack_t.
 * @stack: A pointer to the top
 * @value: line number.
 */
void pint(stack_t **stack, unsigned int value)
{
	stack_t *tmp_node;

	tmp_node = *stack;
	if (*stack != NULL)
		printf("%i\n", tmp_node->n);
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", value);
		exit(EXIT_FAILURE);
	}
}

/**
 * pop - Removes the top value element.
 * @stack: A pointer to the top
 * @value: line number.
 */
void pop(stack_t **stack, unsigned int value)
{
	stack_t *tmp, *eraser;

	tmp = *stack;
	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", value);
		exit(EXIT_FAILURE);
	}
	eraser = *stack;
	*stack = tmp->next;
	tmp = tmp->next;
	if (tmp != NULL)
		tmp->prev = NULL;
	free(eraser);
}
