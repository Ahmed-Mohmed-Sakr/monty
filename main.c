#include "monty.h"

/**
 * main - entery point to start interpreter for Monty ByteCodes files.
 *
 * @argc: argments count.
 * @argv: values passed program.
 *
 * Return: 0 on Success
 */
int main(int argc, char **argv)
{
	FILE *opcode_file;
	char *opcode;
	size_t line_len = 0;
	unsigned int line_num = 1;
	stack_t *stack = NULL;
	char *line = NULL;

	status = 0;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	opcode_file = fopen(argv[1], "r");
	if (opcode_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file <%s>\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (my_getline(&line, &line_len, opcode_file) != -1)
	{
		/*
		if (status == -1)
			break;
*/
		opcode = strtok(line, " \t\n");
		execute_instruction(opcode, line_num, &stack);

		line_num++;
		free(line);
		line = NULL;
	}
	if (line != NULL)
		free(line);
	free_stack(&stack);
	fclose(opcode_file);
	if (status == -1)
		exit(EXIT_FAILURE);
	return (0);
}
