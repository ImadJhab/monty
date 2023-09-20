#include "monty.h"
/**
 * push - push a node into the stack
 * @stck: double pointer to a list
 * @ln: line number
 * @tracker: tracker
*/
void push(char *ln, stack_t **stck, unsigned int tracker)
{
	int n;

	ln = strtok(NULL, " \t\n");
	if (!ln || check(ln) == 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", tracker);
		exit(EXIT_FAILURE);
	}
	n = atoi(ln);
	PUSH_VAL = n;
	help_push(stck, tracker);
}
/**
 * help_push - helps the push func
 * @stck: head of the stack
 * @tracker: void
 * Return: none
 */
void help_push(stack_t **stck, unsigned int tracker)
{
	stack_t *new_stack;
	(void)tracker;

	new_stack = malloc(sizeof(stack_t));
	if (new_stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_stack->n = PUSH_VAL;
	new_stack->prev = NULL;
	new_stack->next = *stck;
	if (*stck)
	{
		(*stck)->prev = new_stack;
	}
	*stck = new_stack;
}
