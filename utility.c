#include "monty.h"

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
		*n = 1;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}
	while ((c = getc(stream)) != EOF)
	{
		if (pos + 1 >= *n)
		{
			new_n = *n + 1;
			new_lineptr = malloc(new_n);
			if (new_lineptr == NULL)
				return (-1);
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
		return (-1);
	memcpy(new_lineptr, *lineptr, pos + 1);
	free(*lineptr);
	*lineptr = new_lineptr;
	return (pos + 1);
}


/**
 * is_all_digits - check that all string is digits.
 *
 * @str: string to check it.
 *
 * Return: 0 if not and retuen 1 if all is digits.
 */
int is_all_digits(const char *str)
{
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
