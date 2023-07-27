#include "shell.h"

/**
 * interactiveMode - returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactiveMode(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * delimeter - checks if character is a delimeter
 * @ch: the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int delimeter(char ch, char *delim)
{
	while (*delim)
		if (*delim++ == ch)
			return (1);
	return (0);
}

/**
 * _isalpha - checks for alphabetic character
 * @ch: The character to input
 * Return: 1 if ch is alphabetic, 0 otherwise
 */

int _isalpha(int ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _tointeger - converts a string to an integer
 * @str: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int _tointeger(char *str)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; str[i] != '\0' && flag != 2; i++)
	{
		if (str[i] == '-')
			sign *= -1;

		if (str[i] >= '0' && str[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (str[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

