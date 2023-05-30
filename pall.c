#include <stdio.h>
#include "monty.h"
#include "externs.h"

/**
 * pall - function of type void
 *
 * @ins: parameter of type struct
 * @ln: parameter of type int
 *
 * Return: void
 */
void pall(stack_t **ins, unsigned int ln)
{
	stack_t *nov;

	(void)ln;
	nov = *ins;
	while (nov)
	{
		printf("%d\n", nov->n);
		nov = nov->next;
	}
}
