#include "monty.h"
/**
 * mod - computes the rest of the division
 * @stck: stack
 * @tracker: tracker
*/
void mod(stack_t **stck, unsigned int tracker)
{
	int total;

	if (*stck == NULL || (*stck)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", tracker);
		exit(EXIT_FAILURE);
	}
	if ((*stck)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", tracker);
		exit(EXIT_FAILURE);
	}
	(*stck) = (*stck)->next;
	total = (*stck)->n % (*stck)->prev->n;
	(*stck)->n = total;
	free((*stck)->prev);
	(*stck)->prev = NULL;
}
