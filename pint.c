#include "monty.h"
/**
 * pint - prints the value at the top of the stack
 * @stck: stack
 * @tracker: tracker
*/
void pint(stack_t **stck, unsigned int tracker)
{
	if (*stck == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", tracker);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stck)->n);
}
