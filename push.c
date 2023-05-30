#include <stdlib.h>
#include <stdio.h>
#include "monty.h"
#include "externs.h"

/**
 * push - function of type void
 * @ins: parameter of type struct
 * @lno: parameter of type int
 *
 * Return: void
 */
void push(stack_t **ins, unsigned int lno)
{
	stack_t *new;

	(void)lno;
	new = deque_value();
	new->next = *ins;

	if (new->next)
		new->next->prev = new;

	*ins = new;
}

/**
 * push_error - function of type void
 * @nd: parameter of type struct
 *
 * Return: void
 */
void push_error(queue_t *nd)
{
	fprintf(stderr, "L%d: usage: push integer\n", nd->line_number);
	exit(EXIT_FAILURE);
}
