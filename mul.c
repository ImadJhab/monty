#include "monty.h"
/**
 * mul -  multiplies the second top element of the stack
 * @stck: stack
 * @tracker: tracker
*/
void mul(stack_t **stck, unsigned int tracker)
{
	int total;

	if (*stck == NULL || (*stck)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", tracker);
		exit(EXIT_FAILURE);
	}
	(*stck) = (*stck)->next;
	total = (*stck)->n * (*stck)->prev->n;
	(*stck)->n = total;
	free((*stck)->prev);
	(*stck)->prev = NULL;
}
