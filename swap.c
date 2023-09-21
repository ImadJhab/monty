#include "monty.h"
/**
 * swap - swaps the top two elements of the stack
 * @stck: stack
 * @tracker: tracker
*/
void swap(stack_t **stck, unsigned int tracker)
{
	int counter;

	if (*stck == NULL || (*stck)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", tracker);
		exit(EXIT_FAILURE);
	}
	counter = (*stck)->n;
	(*stck)->n = (*stck)->next->n;
	(*stck)->next->n = counter;
}
