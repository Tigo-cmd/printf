#include "main.h"
/**
* _ret_hex_up - handles the hexadecimal comnersion in uppercase.
* @passed: argument starter.
*
* Return: char_counts.
*/
int _ret_hex_up(va_list passed)
{
	char inc[31 + 1];
	char num[] = "0123456789ABCDEF";
	int ch;
	int trace = 0;
	int b;
	int ver = 0;
	unsigned int ent;

	ent = va_arg(passed, unsigned int);
	while (ent != 0)
	{
		ch = ent % 16;
		inc[trace++] = num[ch];
		ent = ent / 16;
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
* _ret_hex_low - handles the hexadecimal comnersion in lowercase.
* @passed: argument starter.
*
* Return: char_counts.
*/
int _ret_hex_low(va_list passed)
{
	char inc[31 + 1];
	char num[] = "0123456789abcdef";
	int ch;
	int trace = 0;
	int b;
	int ver = 0;
	unsigned int ent;

	ent = va_arg(passed, unsigned int);
	while (ent != 0)
	{
		ch = ent % 16;
		inc[trace++] = num[ch];
		ent = ent / 16;
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
* _retrev - handles the reverse string conversion in lowercase.
* @passed: argument starter.
*
* Return: char_counts.
*/
int _retrev(va_list passed)
{
	char *n;
	char swap;
	int inc = 0,rev = 0;

	n = va_arg(passed, char *);
	if (n == NULL)
	{
		n = "NULL";
		return (-1);
	}
	while (n[inc])
	{
		inc++;
	}
	inc = inc - 1;
	while (inc >= 0)
	{
		swap = n[inc];

		write(1, &swap, 1);
		inc--;
		rev++;
	}
	return (rev);
}
