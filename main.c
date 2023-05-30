#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "externs.h"
#include "monty.h"

queue_t *queue = NULL;
queue_t *queue_tail = NULL;
stack_t *values = NULL;
stack_t *values_tail = NULL;

/**
 * main - function of type void
 * @argc: parameter of type int
 * @argv: list of command line arguements
 *
 * Return: vla
 */
int main(int argc, char **argv)
{
	FILE *mlf;
	char *ln = NULL;
	size_t ind = 0;
	int lno = 0;
	ssize_t rw;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE : mf\n");
		exit(EXIT_FAILURE);
	}
	mlf = fopen(argv[1], "r");
	if (!mlf)
	{
		fprintf(stderr, "Error: error while handle %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((rw = getline(&ln, &ind, mlf)) != -1)
	{
		enqueue(ln, ++lno);
		ln = NULL;
		ind = 0;
	}
	interpret();
	fclose(mlf);
	free(ln);
	free_queue();
	free_values();
	return (EXIT_SUCCESS);
}
