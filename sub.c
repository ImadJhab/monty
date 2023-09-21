#include "monty.h"
/**
 * sub - subtracts the top element of the stack
 * @stck: stack
 * @tracker: tracker
*/
void sub(stack_t **stck, unsigned int tracker)
{
	int subtract;

	if (*stck == NULL || (*stck)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", tracker);
		exit(EXIT_FAILURE);
	}
	subtract = (*stck)->n - (*stck)->next->n;
	pop(stck, tracker);
	(*stck)->n = subtract;
}
