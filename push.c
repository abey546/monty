#include "monty.h"

/**
 * push - adds a new node at the end of the stack
 * @line: line number of commands in the file
 * @strings: a buffer where commands are stored
 * @file: file to read from
 * @buffer: commands
 * Return: 0 on success
 */

int push(int line, FILE *file, char *buffer, char **strings)
{
	stack_t *current;
	stack_t *newlist;
	char *c;

	if (strings[1] == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		cleanup(file, buffer, strings);
		exit(EXIT_FAILURE);
	}

	for (c = strings[1]; *c; c++)
	{
		if (!isdigit(*c) && *c != '-')
		{
			fprintf(stderr, "L%d: usage: push integer\n", line);
			cleanup(file, buffer, strings);
			exit(EXIT_FAILURE);
		}
	}

	newlist = malloc(sizeof(stack_t));
	if (newlist == NULL)
	{
		cleanup(file, buffer, strings);
		free_tokens(strings);
		malloc_error();
	}

	newlist->n = atoi(strings[1]);
	newlist->next = NULL;

	if (head == NULL)
	{
		newlist->prev = NULL;
		head = newlist;
	}
	else
	{
		current = head;
		while (current->next != NULL)
			current = current->next;

		current->next = newlist;
		newlist->prev = current;
	}
	free_tokens(strings);
	strings = NULL;

	return (0);
}
