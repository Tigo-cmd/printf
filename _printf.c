#include "main.h"
/**
* _printf - my clone of the printf function
* @format: the character string. it is to be strictly followed
*
* Decsription: function that produces output according to a format
* Return: number of charcters print
*/
int _printf(const char *format, ...)
{
	char *chr = (char *)format;
	int ch = 0;
	int i = 0, c = 0;
	int print;

	va_list passed;

	if (format == NULL)
		return (-1);

	va_start(passed, format);
	while (chr[i] != '\0')
	{
		if (chr[i] == '%')
		{
			i++;
			switch (chr[i])
			{
				case '-':
					++i;
					print = _fprintf(format, &i, passed);
					break;
				case '0':
					i++;
					print = _fprintf(format, &i, passed);
					break;
				case '+':
					i++;
					print = _fprintf(format, &i, passed);
					break;
				case '#':
					i++;
					print = _fprintf(format, &i, passed);
					break;
				case ' ':
					i++;
					print = _fprintf(format, &i, passed);
					break;
				default:
					 print = _fprintf(format, &i, passed);
					break;
				if (print == -1)
					return (print);
			}
			ch = ch + print;
		}
		else
		{
			c = write(1, &chr[i], 1);
			if (c == -1)
				return (-1);
			ch++;
		}
		i++;
	}
	return (ch);
}
