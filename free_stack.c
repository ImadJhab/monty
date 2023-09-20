#include "monty.h"
/**
 * frees_the_stack - frees the stack
 * @stck: stack
*/
void frees_the_stack(stack_t *stck)
{
	stack_t *next;

	if (stck == NULL)
	{
		return;
	}

	while (stck)
	{
		next = stck;
		stck = stck->next;
		free(next);
	}
	free(stck);
}
/**
 * check - check if a string consists of integers
 * @s: string
 * Return: 0 or 1
 */
int check(char *s)
{
	int count = 0;

	if (s[0] == '-')
	{
		count++;
	}
	while (s[count] != '\0')
	{
		if (s[count] < 48 || s[count] > 57)
		{
			return (1);
		}
		count++;
	}
	return (0);
}
