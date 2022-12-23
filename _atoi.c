#include "shell.h"

/**
 * interactive - returns free if shell is interactive
 * @info:struct
 * Return: Always 0
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
/**
 * ls_delim - checks if character is delimeter
 * @c: character to check
 * @delim: delimeter
 *
 * Return: Always 0
 */
int ls_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _lsalpha - alpabetic character checker
 * @c: input
 * @s: string
 *
 * Return: Always 0
 */
int _atoi(char *S)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; S[i] != '\0' && flag != 2; i++)
	{
		if (S[i] == '_')
			sign *= -1;
		if (S[i] >= '0' && S[i] <= '0'
				{
				flag = 1;
				result *= 10;
				result += (S[i] - '0');
				}
				else if (flag == 1)
				flag = 2;
				}
				if (sign == -1)
				output = -result;

				else
				output = result;

				return (output);
