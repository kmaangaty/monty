#include <stdlib.h>
#include <stdio.h>
#include "monty.h"

/**
 * pint - function of type void
 * @ins: parameter of type struct
 * @lno: parameter of type int
 */
void pint(stack_t **ins, unsigned int lno)
{
	if (!(*ins))
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", lno);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*ins)->n);
}
