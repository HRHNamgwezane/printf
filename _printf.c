#include "main.h"

int _printf(const char *format, ...)
{
	int printed_chars = 0;
	int buffer_index = 0;
	char buffer[BUFF_SIZE];
	char *str = va_arg(args, char *);
	va_list args;
	int i;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buffer_index++] = format[i];
			if (buffer_index == BUFF_SIZE)
			{
				write(1, buffer, buffer_index);
				printed_chars += buffer_index;
				buffer_index = 0;
			}
			else
			{
				printed_chars++;
			}
		}
		else
		{
			i++;
			switch (format[i])
			{
				case 'c':
					buffer[buffer_index++] = va_arg(args, int);
					break;
				case 's':
					{
						while (*str != '\0')
						{
							buffer[buffer_index++] = *str++;
							if (buffer_index == BUFF_SIZE)
							{
								write(1, buffer, buffer_index);
								printed_chars += buffer_index;
								buffer_index = 0;
							}
							else
							{
								printed_chars++;
							}
						}
					}
					break;
				case '%':
					buffer[buffer_index++] = '%';
					break;
				default:
					break;
			}
		}
	}
	if (buffer_index > 0)
	{
		write(1, buffer, buffer_index);
		printed_chars += buffer_index;
	}
	va_end(args);

	return printed_chars;
}
