#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
* _printf - my clone of the printf function
* @format: the character string. it is to be strictly followed
*
* Decsription: function that produces output according to a format
* Return: number of charcters printed
*/
int _printf(const char *format, ...)
{
	char *chr = (char *)format;
	int ch = 0;
	char c;
	char *s;
	char per;

	va_list str;

	va_start(str, format);
	if (format == NULL)
		return (-1);
	while (*chr)
	{
		if (*chr == '%')
		{
			chr++;
			switch (*chr)
			{
				case '\0':
					break;
					break;
				case 'c':
					c = va_arg(str, int);
					write(1, &c, 1);
					ch++;
					break;
				case 's':
					s = va_arg(str, char *);
					for (; *s; s++)
					{
						write(1, s, 1);
						ch++;
					}
					break;
				case '%':
					per = '%';
					write(1, &per, 1);
					ch++;
					break;
				default:
					break;
			}
		}
		else
		{
			write(1, chr, 1);
			ch++;
		}
		chr++;
	}
	va_end(str);
	return (ch);

}