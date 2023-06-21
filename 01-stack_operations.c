#include "monty.h"

/**
 *
*/
void stack_push(stack_t **stack, unsigned int line_num)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	if (new_node == NULL){
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(arg);
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
*/
void stack_pall(stack_t **stack, unsigned int line_num)
{
	stack_t *node = *stack;
	
	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}
