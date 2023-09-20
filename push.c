#include "monty.h"
/**
 * push - push a node into the stack
 * @stck: double pointer to a list
 * @ln: line number
 * @tracker: tracker
*/
void push(stack_t **stck, char *ln, unsigned int tracker)
{
	int count;
	stack_t *new_stack;

	new_stack = malloc(sizeof(stack_t));
	if (new_stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (ln == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", tracker);
		exit(EXIT_FAILURE);
	}
	for (count = 0; ln[count]; count++)
	{
		if (ln[0] == '-' && count == 0)
		{
			continue;
		}
		if (ln[count] < 48 || ln[count] > 57)
		{
			fprintf(stderr, "L%d: usage: push integer\n", tracker);
			exit(EXIT_FAILURE);
		}
	}
	new_stack->n = atoi(ln);
	new_stack->prev = NULL;
	new_stack->next = NULL;
	if (*stck != NULL)
	{
		new_stack->next = *stck;
		(*stck)->prev = new_stack;
	}
	*stck = new_stack;
}
