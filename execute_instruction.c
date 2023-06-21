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
		{NULL, NULL}
	};

	if (opcode == NULL)
		return;

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
		{
			instructions[i].f(stack, line_n);
			return;
		}
	}
	printf("L%d: unknown instruction %s\n", line_n, opcode);
	exit(EXIT_FAILURE);
}
