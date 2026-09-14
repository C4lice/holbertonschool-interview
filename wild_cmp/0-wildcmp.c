#include "holberton.h"

/**
 * wildcmp - Compares two strings, where s2 may contain the
 * special character '*' that can replace any sequence of
 * characters (including an empty one)
 * @s1: first string
 * @s2: second string, may contain '*'
 *
 * Return: 1 if the strings can be considered identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	if (*s2 == '*')
		return (wildcmp(s1, s2 + 1) ||
			(*s1 != '\0' && wildcmp(s1 + 1, s2)));

	if (*s1 == '\0' || *s2 == '\0')
		return (*s1 == '\0' && *s2 == '\0');

	if (*s1 != *s2)
		return (0);

	return (wildcmp(s1 + 1, s2 + 1));
}
