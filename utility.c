#include "monty.h"

/**
 * allocte_error - print error message.
 *
 * Return: -1
 */
int allocte_error(void)
{
	printf("Error: malloc failed\n");
	status = -1;
	return (-1);
}

/**
 * my_getline - clone to getline().
 *
 * @lineptr: place to write data.
 * @n: buffer.
 * @stream: file to read from.
 *
 * Return: line length.
 */
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t pos = 0;
	int c;
	size_t new_n;
	char *new_lineptr;

	if (*lineptr == NULL)
	{
		*n = 220;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return (allocte_error());
	}
	while ((c = getc(stream)) != EOF)
	{
		if (pos + 1 >= *n)
		{
			new_n = *n + 10;
			new_lineptr = malloc(new_n);
			if (new_lineptr == NULL)
				return (allocte_error());
			memcpy(new_lineptr, *lineptr, pos);
			free(*lineptr);
			*lineptr = new_lineptr;
			*n = new_n;
		}
		(*lineptr)[pos++] = c;
		if (c == '\n')
			break;
	}
	if (pos == 0)
		return (-1);
	(*lineptr)[pos] = '\0';
	new_lineptr = malloc(pos + 1);
	if (new_lineptr == NULL)
		return (allocte_error());
	memcpy(new_lineptr, *lineptr, pos + 1);
	free(*lineptr);
	*lineptr = new_lineptr;
	return (pos + 1);
}


/**
 * is_integer - check that string is int.
 *
 * @str: string to check it.
 *
 * Return: 0 if not and retuen 1 if all is digits.
 */
int is_integer(const char *str)
{
	if (*str == '-')
		str++;

	if (*str == '\0')
		return (0);

	while (*str != '\0')
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
