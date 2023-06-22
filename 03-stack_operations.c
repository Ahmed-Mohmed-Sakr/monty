#include "monty.h"


/**
 * stack_mul -  mul multiplies the second top element
 * of the stack with the top element of the stack.
 *
 * @stack: refrance to stack to print it.
 * @line_num: line num in Monty ByteCodes file.
 *
 * Return: void.
*/
void stack_mul(stack_t **stack, unsigned int line_num)
{
	stack_t *node;

	(void) line_num;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L<%d>: can't mul, stack too short\n", line_num);
		status = -1;
		return;
	}

	node = *stack;
	(*stack) = (*stack)->next;

	(*stack)->n = ((*stack)->n) * (node->n);
	free(node);
}


/**
 * stack_mod - mod computes the rest of the division of the second top element
 * of the stack by the top element of the stack
 *
 * @stack: refrance to stack to print it.
 * @line_num: line num in Monty ByteCodes file.
 *
 * Return: void.
*/
void stack_mod(stack_t **stack, unsigned int line_num)
{
	stack_t *node;

	(void) line_num;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L<%d>: can't mod, stack too short\n", line_num);
		status = -1;
		return;
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L<%d>: division by zero\n", line_num);
		status = -1;
		return;
	}

	node = *stack;
	(*stack) = (*stack)->next;

	(*stack)->n = ((*stack)->n) % (node->n);
	free(node);
}
