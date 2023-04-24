#include "main.h"

int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	int count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					{
						char c = va_arg(args, int);
						putchar(c);
						count++;
						break;}
				case 's':
					{
						char *str = va_arg(args, char*);
						while (*str)
						{
							putchar(*str);
							str++;
							count++;
						}
						break;
					}
				case '%':
					{
						putchar('%');
						count++;
						break;
					}
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return count;
}
int main(int argc, char *argv[])
{
	_printf("Hello, %s! The answer is %d%c\n", "world", 42, '.');
	return 0;
}
