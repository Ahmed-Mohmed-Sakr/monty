#include "monty.h"

/**
 */
void execute_instruction(char *opcode, long int line_num, char *datastruc_type)
{
	int i;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
		{
			if(strcmp(datastruc_type, "stack") == 0)
				instructions[i].f(stack, line_num);
			return;
		}
	}
	printf("L%ld: unknown instruction %s\n", line_num, opcode);
	exit(EXIT_FAILURE);
}
