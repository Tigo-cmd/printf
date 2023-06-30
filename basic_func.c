#include "main.h"
/**
* _retch - prints the (%c) conversion specifier
* @passed: first argument parameter
*
* Return: char_count printed
*/
int _retch(va_list passed)
{
	char chr = va_arg(passed, int);

	return (write(1, &chr, 1));
}

/**
* _retstr - handles the (%s) conversion specifier
* @passed: first argument parameter
*
* Return: string_count printed
*/
int _retstr(va_list passed)
{
	int i = 0;
	char *str = va_arg(passed, char *);

	while (str[i] != '\0')
	{
		i++;
	}
	return (write(1, &str[0], i));
}
/**
* _retbin - prints the binary  conversion specifier
* @passed: first argument parameter
*
* Return: binary_count printed
*/
int _retbin(va_list passed)
{
	char inc[31 + 1];
	int trace = 0;
	int b, c;
	int ver = 0;
	unsigned int ent;

	ent  = va_arg(passed, unsigned int);

	while (ent != 0)
	{
		c = ent % 2;
		if (c == 0)
		{
			inc[++trace] = '0';
		}
		else
		{
			inc[trace++] = '1';
		}
		ent = ent / 2;
	}
	b = trace - 1;
	while (b >= 0)
	{
		ver = write(1, &inc[b], 1);
		if (ver == -1)
			return (-1);
		b--;
	}
	return (trace);
}
/**
* _retper - prints the percent(%%) conversion specifier
* @passed: first argument parameter
*
* Return: char_count printed
*/
int _retper(va_list passed)
{
	(void)(passed);

	return (write(1, "%%", 1));
}
/**
* _retint - prints the (%i%d) conversion specifier
* @passed: first argument parameter
*
* Return: int_count printed
*/
int _retint(va_list passed)
{
	int ent;
	int bit;
	char p = '-';
	char inc[31 + 1];
	int trace = 0;
	int b = 0;
	int negcheck = 0;

	ent = va_arg(passed, int);
	if (ent < 0)
	{
		ent = ent / -1;
		negcheck = 1;
	}
	if (ent == 0)
		inc[trace = trace + 1] = '0';
	do {
		bit = ent % 10;
		inc[++trace] = bit + '0';
		ent = ent / 10;
	} while (ent > 0);

	if (negcheck)
		inc[trace++] = p;
	b = trace - 1;
	while (b >= 0)
	{
		write(1, &inc[b], 1);
		b--;
	}
	return (trace);
}
