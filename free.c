#include "monty.h"
/**
 * free_stack - to free stack.
 *
 * @stack: stack to free.
 *
 * Return: void.
 */
void free_stack(stack_t **stack)
{
	stack_t *node = *stack;
	while (node != NULL)
	{
		stack_t *next = node->next;
		free(node);
		node = next;
	}
	*stack = NULL;
}
