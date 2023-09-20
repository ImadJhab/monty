#include "monty.h"
/**
 * pop - removes the top element of the stack
 * @stck: stack
 * @tracker: tracker
 * Return: none
*/
void pop(stack_t **stck, unsigned int tracker)
{
	stack_t *temp;

	temp = *stck;

	if (!*stck)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", tracker);
		exit(EXIT_FAILURE);
	}
	temp = temp->next;
	free(*stck);
	*stck = temp;
}
