#include "monty.h"
/**
 * main - main function of monty
 * @argc: argv size
 * @argv: double pointer
 * Return: EXIT_FAILURE when errors
*/
int main(int argc, char **argv)
{

	FILE *Sf;
	char buff[1024], *opcode;
	int tracker = 0;
	stack_t *stack = NULL;
	const char *DELIM = " \t\n";

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	Sf = fopen(argv[1], "r");
	if (!Sf)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(buff, 1024, Sf))
	{
		tracker++;
		opcode = strtok(buff, DELIM);
		if (comm(opcode, tracker) == 1)
		{
			continue;
		}
		if (strcmp(opcode, "nop") == 0)
		{
			continue;
		}
		else if (opcode)
		{
			opcode_finder(opcode, &stack, tracker);
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
void opcode_finder(char *opcode, stack_t **stck, int tracker)
{
	if (strcmp(opcode, "push") == 0)
		push(opcode, stck, tracker);
	else if (strcmp(opcode, "pall") == 0)
		pall(stck, tracker);
	else if (strcmp(opcode, "pint") == 0)
		pint(stck, tracker);
	else if (strcmp(opcode, "pop") == 0)
		pop(stck, tracker);
	else if (strcmp(opcode, "swap") == 0)
		swap(stck, tracker);
	else if (strcmp(opcode, "add") == 0)
		add(stck, tracker);
	else if (strcmp(opcode, "sub") == 0)
		sub(stck, tracker);
	else if (strcmp(opcode, "div") == 0)
		_div(stck, tracker);
	else if (strcmp(opcode, "mul") == 0)
		mul(stck, tracker);
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", tracker, opcode);
		exit(EXIT_FAILURE);
	}
}
/**
 * comm - is comment
 * @tok: token
 * @count: num of lines
 * Return: 1 or -1
 */
int comm(char *tok, int count)
{
	if (tok == NULL || tok[0] == '#')
	{
		count++;
		return (1);
	}
	return (-1);
}
