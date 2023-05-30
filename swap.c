#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
#include "externs.h"

/**
 * swap - function of type void
 *
 * @ins: pointer to pointer to the top node in stack
 * @lno: the line number of the instruction
 *
 * Return: void
 */
void swap(stack_t **ins, unsigned int lno)
{
	stack_t *o;
	stack_t *t;

	if (!(*ins)->next)
	{
		fprintf(stderr, "L%u: can't swap\n", lno);
		exit(EXIT_FAILURE);
	}
	o = *ins;
	t = (*ins)->next;
	o->next = t->next;
	o->next->prev = o;
	t->next = o;
	t->prev = NULL;
	o->prev = t;
	*ins = t;
}
