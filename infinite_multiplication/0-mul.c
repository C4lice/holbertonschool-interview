#include <stdlib.h>
#include <stdio.h>
#include "holberton.h"

/**
 * is_valid - Checks if a string contains only digits
 * @str: string to check
 *
 * Return: 1 if valid, 0 otherwise
 */
static int is_valid(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (i > 0);
}

/**
 * str_len - Returns the length of a string
 * @str: string to measure
 *
 * Return: length of the string
 */
static int str_len(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		;
	return (i);
}

/**
 * main - Entry point, multiplies two large positive numbers
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	int len1, len2, i, j, prod;
	int *result;
	int total;
	int start;

	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}
	if (!is_valid(argv[1]) || !is_valid(argv[2]))
	{
		printf("Error\n");
		return (98);
	}
	len1 = str_len(argv[1]);
	len2 = str_len(argv[2]);
	total = len1 + len2;
	result = calloc(total, sizeof(int));
	if (result == NULL)
	{
		printf("Error\n");
		return (98);
	}
	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			prod = (argv[1][i] - '0') * (argv[2][j] - '0');
			prod += result[i + j + 1];
			result[i + j + 1] = prod % 10;
			result[i + j] += prod / 10;
		}
	}
	start = 0;
	while (start < total - 1 && result[start] == 0)
		start++;
	for (i = start; i < total; i++)
		_putchar('0' + result[i]);
	_putchar('\n');
	free(result);
	return (0);
}

