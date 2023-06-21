#include "monty.h"

/**
 * stack_push - to push new element in the stack
 *
 * @stack: refrance to stack to push onit
 * @line_num: line num in Monty ByteCodes file.
 *
 * Return: void.
*/
void stack_push(stack_t **stack, unsigned int line_num)
{
	char *arg = strtok(NULL, " \t\n");
	stack_t *new_node;

	if (arg == NULL || !is_integer(arg))
	{
		printf("L<%d>: usage: push integer\n", line_num);
		status = -1;
		return;
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		status = -1;
		return;
	}

	new_node->n = atoi(arg);
	new_node->prev = NULL;
	new_node->next = NULL;
	if (*stack != NULL)
		new_node->next = *stack;
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
void stack_pall(stack_t **stack, unsigned int line_num)
{
	stack_t *node;

	if (stack == NULL || *stack == NULL)
		return;

	(void) line_num;
	node = *stack;
	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}


/**
 * stack_pint - The opcode pint prints the value at the top of the stack.
 *
 * @stack: refrance to stack to print it.
 * @line_num: line num in Monty ByteCodes file.
 *
 * Return: void.
*/
void stack_pint(stack_t **stack, unsigned int line_num)
{
	(void) line_num;

	if (stack == NULL || *stack == NULL)
	{
		printf("L<%d>: usage: can't pint, stack empty\n", line_num);
		status = -1;
		return;
	}

	printf("%d\n", (*stack)->n);
}
