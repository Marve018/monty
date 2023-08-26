#include "monty.h"

/**
 * free_head - free a double linked list
 * @head: head of the linked list
 * Return: Void
 */

void free_head(stack_t *head)
{
	stack_t *aux;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		aux = head;
		head = head->next;
		free(aux);
	}
}
