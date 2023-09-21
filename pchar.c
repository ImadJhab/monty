#include "monty.h"
/**
 * pchar - prints the char at the top of the stack
 * @stck: stack
 * @tracker: tracker
*/
void pchar(stack_t **stck, unsigned int tracker)
{
	int ASCII;

	if (stck == NULL || *stck == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", tracker);
		exit(EXIT_FAILURE);
	}
	ASCII = (*stck)->n;
	if (ASCII < 0 || ASCII > 127)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", tracker);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", ASCII);
}
