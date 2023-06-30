#include "main.h"
/**
* _ret_octal - prints the octal conversion specifier.
* @passed: argument starter
*
* Return: char_count
*/
int _ret_octal(va_list passed)
{
	const char oct[] = "01234567";
	int trace = 0;
	int ver = 0;
	int b, c;
	char inc[31 + 1];
	unsigned int ent;

	ent = va_arg(passed, unsigned int);
	while (ent != 0)
	{
		c = ent % 8;
		inc[trace++] = oct[c];
		ent = ent / 8;
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
* _ret_usign - handles the unsigned specifier.
* @passed: argument starter.
*
* Return: char_counted.
*/
int _ret_usign(va_list passed)
{
	const char digit[] = "0123456789";
	int trace = 0;
	int ver = 0;
	int b, c;
	char inc[31 + 1];
	unsigned int ent;

	ent = va_arg(passed, unsigned int);
	while (ent != 0)
	{
		c = ent % 10;
		inc[trace++] = digit[c];
		ent = ent / 10;
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
