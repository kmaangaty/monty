#include <stdio.h>
#include <stdlib.h>
#include "externs.h"
#include "monty.h"

/**
 * deque - function of type struct
 *
 * Return: node[-1]
 */
queue_t *deque(void)
{
	queue_t *nd;

	if (!queue_tail)
		return (NULL);
	nd = queue_tail;
	queue_tail = queue_tail->prev;

	return (nd);
}

/**
 * deque_value - function of type void
 *
 * Return: node[-1]
 */
stack_t *deque_value(void)
{
	stack_t *nd;

	if (!values_tail)
		return (NULL);
	nd = values_tail;
	values_tail = values_tail->prev;
	nd->prev = NULL;

	return (nd);
}

/**
 * enqueue - function of type void
 *
 * @ln: parameter of type char
 * @lno: parameter of type int
 *
 * Return: void
 */
void enqueue(char *ln, int lno)
{
	queue_t *gq;

gq =  malloc(sizeof(queue_t));
	if (!gq)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	gq->line = ln;
	gq->line_number = lno;
	if (queue)
	{
		gq->next = queue;
		queue->prev = gq;
		queue = gq;
	}
	else
	{
		queue = gq;
		queue_tail = gq;
	}
}

/**
 * enqueue_values - function of type void
 *
 * @ind: parameter of type int
 *
 * Return: void
 */
void enqueue_values(int ind)
{
	stack_t *ins;

	ins = malloc(sizeof(stack_t));
	if (!ins)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	ins->n = ind;
	ins->next = values;
	if (ins->next)
		ins->next->prev = ins;
	values = ins;
	if (!values_tail)
		values_tail = values;
}

/**
 * print_queue - function of type void
 *
 * Return: void
 */
void print_queue(void)
{
	queue_t *mok;

	mok = queue;
	while (mok)
	{
		printf("L%d: %s", mok->line_number, mok->line);
		mok = mok->next;
	}
}
