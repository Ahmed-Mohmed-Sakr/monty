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
		fprintf(stderr, "L<%d>: can't swap, stack too short\n", line_num);
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

	(void) line_num;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L<%d>: can't add, stack too short\n", line_num);
		status = -1;
		return;
	}

	node = *stack;
	(*stack) = (*stack)->next;

	(*stack)->n = ((*stack)->n) + (node->n);
	free(node);
}


/**
 * stack_sub - sub subtracts the top element of the stack from
 * the second top element of the stack.
 *
 * @stack: refrance to stack to print it.
 * @line_num: line num in Monty ByteCodes file.
 *
 * Return: void.
*/
void stack_sub(stack_t **stack, unsigned int line_num)
{
	stack_t *node;

	(void) line_num;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L<%d>: can't sub, stack too short\n", line_num);
		status = -1;
		return;
	}

	node = *stack;
	(*stack) = (*stack)->next;

	(*stack)->n = ((*stack)->n) - (node->n);
	free(node);
}


/**
 * stack_div -  opcode div divides the second top element
 * of the stack by the top element of the stack.
 *
 * @stack: refrance to stack to print it.
 * @line_num: line num in Monty ByteCodes file.
 *
 * Return: void.
*/
void stack_div(stack_t **stack, unsigned int line_num)
{
	stack_t *node;

	(void) line_num;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L<%d>: can't div, stack too short\n", line_num);
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

	(*stack)->n = ((*stack)->n) / (node->n);
	free(node);
}
