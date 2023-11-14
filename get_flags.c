#include "main.h"
#include <string.h>

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	int flags = 0;
	int curr_i = *i + 1;
	const char *flag = strchr(FLAGS_CH, format[curr_i]);
	int flag_index;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (flag)
		{
			flag_index = flag - FLAGS_CH;
			flags |= FLAGS_ARR[flag_index];
		}
		else
		{
			break;
		}
	}

	*i += curr_i - (*i) - 1;
	
	return (flags);
}
