#include <stdlib.h>
#include "monty.h"
#include "externs.h"

/**
 * free_queue - function of type void
 *
 * Return: void
 */
void free_queue(void)
{
	queue_t *nov;

	while (queue)
	{
		nov = queue;
		queue = queue->next;
		free(nov->line);
		free(nov);
	}
}

/**
 * free_values - function of type void
 *
 * Return: void
 */
void free_values(void)
{
	stack_t *nov;

	while (values)
	{
		nov = values;
		values = values->next;
		free(nov);
	}
}

