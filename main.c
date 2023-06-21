#include "monty.h"

/**
 */
void main(int argc, char **argv)
{
	char *delim = " \t\n"; /*glopal var*/
	FILE *file;
	char *line;
	char *opcode;
	size_t line_len = 0;
	long long int line_num = 1;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	opcode_file = fopen(argv[1], "r");
	if (opcode_file == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &line_len, opcode_file))
	{
		opcode = strtok(line, delim);
		execute_instruction(opcode, line_num);
		line_num++;
	}
	free(line);
	fclose(opcode_file);
	return 0;
}
