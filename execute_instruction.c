#include "monty.h"

/**
 * execute_instruction - to execute Monty ByteCodes.
 *
 * @opcode: instruction to exxecute.
 * @line_n: number of line of Monty ByteCodes files.
 * @stack: refrane to stack.
 *
 * return: void.
 */
void execute_instruction(char *opcode, unsigned int line_n, stack_t **stack)
{
	int i;
	instruction_t instructions[] = {
		{"push", stack_push},
		{"pall", stack_pall},
		{"pint", stack_pint},
		{"pop", stack_pop},
		{"swap", stack_swap},
		{"add", stack_add},
		{"sub", stack_sub},
		{"div", stack_div},
		{NULL, NULL}
	};

	if (opcode == NULL || strcmp("nop", opcode) == 0)
		return;

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
		{
			instructions[i].f(stack, line_n);
			return;
		}
	}
	fprintf(stderr, "L<%d>: unknown instruction <%s>\n", line_n, opcode);
	status = -1;
}
