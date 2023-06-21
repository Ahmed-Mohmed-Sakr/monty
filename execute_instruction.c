#include "monty.h"

/**
 * execute_instruction - to execute Monty ByteCodes.
 *
 * @opcode: instruction to exxecute.
 * @line_num: number of line of Monty ByteCodes files.
 * @datastruc_type: to determine the type of datastrcre.
 *
 * return: void.
 */
void execute_instruction(char *opcode, long int line_num, char *datastruc_type)
{
	int i;
	instruction_t instructions[] = {
		{"push", stack_push},
		{"pall", stack_pall},
		{NULL, NULL}
	};

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
		{
			if (strcmp(datastruc_type, "stack") == 0)
				instructions[i].f(stack, line_num);
			return;
		}
	}
	printf("L%ld: unknown instruction %s\n", line_num, opcode);
	exit(EXIT_FAILURE);
}
