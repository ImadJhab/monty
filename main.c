#include "monty.h"
#define DELIM " \t\n"
/**
 * main - main function of monty
 * @argc: argv size
 * @argv: double pointer
 * Return: EXIT_FAILURE when errors
*/
int main(int argc, char **argv)
{

	FILE *Sf;
	char *buffer = NULL, *n, *opcode;
	int tracker = 0;
	stack_t *stack = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	Sf = fopen(argv[1], "r");
	if (Sf == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(1);
	}
	while (fgets(buffer, MAX_SIZE, Sf))
	{
		tracker++;
		opcode = strtok(buffer, DELIM);
		if (opcode == NULL || opcode[0] == '#')
		{
			continue;
		}
		else if (!strcmp(opcode, "push"))
		{
			n = strtok(NULL, DELIM);
			push(&stack, n, tracker);
		}
		else
		{
			opcode_finder(&stack, opcode, tracker);
		}
	}
	fclose(Sf);
	frees_the_stack(stack);
	return (0);
}
/**
 * opcode_finder - tracks the opcodes and finds them
 * @stck: stack
 * @opcode: opcode
 * @tracker: tracker
 * Return: EXIT_SUCCESS
*/
int opcode_finder(stack_t **stck, char *opcode, int tracker)
{
	int count;
	instruction_t codes[] = {
		{"pall", pall}
	};
	for (count = 0; codes[count].opcode; count++)
	{
		if (strcmp(opcode, codes[count].opcode) == 0)
		{
			(codes[count].f)(stck, tracker);
			return (EXIT_SUCCESS);
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", tracker, opcode);
	exit(EXIT_FAILURE);
}
