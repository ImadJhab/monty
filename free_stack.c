#include "monty.h"
/**
 * frees_the_stack - frees the stack
 * @stck: stack
*/
void frees_the_stack(stack_t *stck)
{
	stack_t *next;

	if (stck == NULL)
	{
		return;
	}
	while (stck)
	{
		next = stck;
		stck = stck->next;
		free(next);
	}
	free(stck);
}
