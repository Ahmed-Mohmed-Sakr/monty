#include "monty.h"

/**
 * stack_push - to push new element in the stack
 *
 * @stack: refrance to stack to push onit
 * @line_num: line num in Monty ByteCodes file.
 *
 * Return: void.
*/
void stack_push(stack_t **stack, long int line_num)
{
	char *arg = strtok(NULL, delim);
	stack_t *new_node;

	if (arg == NULL)
	{
		printf("L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
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
 * stack_pall - print elements in the stack.
 *
 * @stack: refrance to stack to print it.
 * @line_num: line num in Monty ByteCodes file.
 *
 * Return: void.
*/
void stack_pall(stack_t **stack, long int line_num)
{
	stack_t *node = *stack;

	(void) line_num;

	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}
