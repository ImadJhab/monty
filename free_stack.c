#include "monty.h"
/**
 * frees_the_stack - frees the stack
 * @stck: stack
*/
void frees_the_stack(stack_t *stck)
{
	stack_t *next;

	while (stck != NULL)
	{
		next = stck->next;
		free(stck);
		stck = next;
	}
}
