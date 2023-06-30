#include "main.h"
/**
* _fprintf.c - handles a coversion specifier to print
* @constant: this is to be strictly followed
* @first: constant starter
* @passed: argument parameter from stdinput
*
* Return: Always(0) success
*/
int _fprintf(const char *constant, int *first, va_list passed)
{
	int a;

	prnt pnt[] = {
		{'c', _retch}, {'i', _retint}, {'b', _retbin},
		{'d', _retint}, {'s', _retstr}, {'%', _retper},
		{'X', _ret_hex_up}, {'x', _ret_hex_low}, {'o', _ret_octal},
		{'u',_ret_usign}, {'\0', NULL}
	};
	for (a = 0; pnt[a].s != '\0'; a++)
	{
		if (constant[*first] == pnt[a].s)
		{
			return (pnt[a].ret(passed));
		}
	}
	if (pnt[a].s == '\0')
	{
		return (-1);
	}
	return (-1);
}
