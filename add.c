#include "monty.h"
/**
 * add - adds the top two elements of the stack
 * @stck: stack
 * @tracker: tracker
*/
void add(stack_t **stck, unsigned int tracker)
{
	int total;

	if (*stck == NULL || (*stck)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", tracker);
		exit(EXIT_FAILURE);
	}
	total = (*stck)->n + (*stck)->next->n;
	pop(stck, tracker);
	(*stck)->n = total;
}
