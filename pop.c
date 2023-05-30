#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
#include "externs.h"

/**
 * pop - function of type void
 * @lno: pointer to the stack
 * @ins: the line number of the current instruction
 *
 * Return: void
 */
void pop(stack_t **ins, unsigned int lno)
{
	if (!(*ins))
	{
		fprintf(stderr, "L%u: can't pop\n", lno);
		exit(EXIT_FAILURE);
	}

	*ins = (*ins)->next;

	if (*ins)
		(*ins)->prev = NULL;
}
