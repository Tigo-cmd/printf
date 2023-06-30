#include "main.h"
/**
* _ret_octal - prints the octal conversion specifier.
* @passed: argument starter
*
* Return: char_count
*/
int _ret_octal(va_list passed)
{
	char oct[] = "01234567";
	int trace = 0;
	int ver;
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
