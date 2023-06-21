#include "monty.h"

/**
 * stack_swap - swap swaps the top two elements of the stack.
 *
 * @stack: refrance to stack to print it.
 * @line_num: line num in Monty ByteCodes file.
 *
 * Return: void.
*/
void stack_swap(stack_t **stack, unsigned int line_num)
{
	stack_t *node;
	int temp;

	(void) line_num;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		printf("L<%d>: can't swap, stack too short\n", line_num);
		status = -1;
		return;
	}

	node = (*stack)->next;
	temp = node->n;
	node->n = (*stack)->n;
	(*stack)->n = temp;
}



/**
 * stack_add -  add adds the top two elements of the stack.
 *
 * @stack: refrance to stack to print it.
 * @line_num: line num in Monty ByteCodes file.
 *
 * Return: void.
*/
void stack_add(stack_t **stack, unsigned int line_num)
{
	stack_t *node;
	int temp;

	(void) line_num;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		printf("L<%d>: can't add, stack too short\n", line_num);
		status = -1;
		return;
	}

	node = *stack;
	(*stack) = (*stack)->next;

	(*stack)->n = ((*stack)->n) + (node->n);
	free(node);
}
