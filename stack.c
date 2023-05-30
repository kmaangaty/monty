#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "monty.h"
#include "externs.h"

/**
 * print_stack - function of type void
 *
 * @ins: parameter of type struct
 *
 * Return: void
 */
void print_stack(stack_t *ins)
{
	stack_t *now;

	now = ins;
	printf("printing st\n");
	while (now)
	{
		printf("%d\n", now->n);
		now = now->next;
	}
}

/**
 * check_instruction - function of type void
 *
 * @pve: parameter of type char
 * @tk: parameter of type char
 * @nd: parameter of type struct
 *
 * Return: error value
 */
static int check_instruction(char *pve, char *tk, queue_t **nd)
{
	long rkm;
	char *rtd;

	errno = 0;
	if (strcmp(pve, tk) == 0)
	{
		if (!strcmp(tk, "pop") || !strcmp(tk, "swap"))
			return (1);
		if (!(strcmp(tk, "pall") == 0 || strcmp(tk, "pint") == 0))
		{
			tk = strtok(NULL, " \n\t\r");
			if (!tk)
				push_error(*nd);
			rkm = strtol(tk, &rtd, 10);
			if (errno || *rtd)
				push_error(*nd);
			enqueue_values((int)rkm);
		}
		return (1);
	}
	return (0);
}

/**
 * interpret - function of type void
 *
 * Return: void
 */
void interpret(void)
{
	int index;
	int fd;
	char *tk;
	queue_t *nd;
	stack_t *ins = NULL;
	instruction_t trm[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{NULL, NULL},
	};

	while ((nd = deque()))
	{
		index = 0;
		fd = 0;
		tk = strtok(nd->line, " \n\t\r");

		if (!tk)
			continue;
		while (trm[index].opcode)
		{
			fd = check_instruction(trm[index].opcode, tk, &nd);
			if (fd)
			{
				trm[index].f(&ins, nd->line_number);
				break;
			}
			++index;
		}
		if (!fd)
			unknown_instruction(nd, tk);
	}
}


/**
 * unknown_instruction - function of type void
 *
 * @nd: parameter of type struct
 * @tk: parameter of type char
 *
 * Return: void
 */
void unknown_instruction(queue_t *nd, char *tk)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", nd->line_number, tk);
	free_queue();
	free_values();
	exit(EXIT_FAILURE);
}

