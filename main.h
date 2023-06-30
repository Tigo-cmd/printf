#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/**
* print - selector for conversions
* @s: handlers checker
* @ret: handlers
*/
typedef struct print{
	char s;
	int (*ret)(va_list);
} prnt;

int _fprintf(const char *constant, int *first, va_list passed);
int _printf(const char *format, ...);

int _retch(va_list passed);
int _retstr(va_list passed);
int _retbin(va_list passed);
int _retper(va_list passed);
int _retint(va_list passed);
int _ret_hex_up(va_list passed);
int _ret_hex_low(va_list passed);
int _ret_octal(va_list passed);
#endif
