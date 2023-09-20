#include "monty.h"
/**
 * pall - print all nodes of the stack
 * @stck: stack
 * @tracker: tracker
*/
void pall(stack_t **stck, unsigned int tracker)
{
	stack_t *current = *stck;
	(void)tracker;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
