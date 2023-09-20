#include "monty.h"
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
