#include "main.h"

/**
 * write_pointer - Writes the pointer to the standard output.
 * @buffer: Buffer array to handle print
 * @index: Current index in the buffer
 * @length: Length of the address
 * @width: Width specification
 * @flags: Active flags
 * @padd: Padding character
 * @extra_c: Extra character ('+' or ' ')
 * @padd_start: Padding start flag
 * Return: Number of characters printed
 */
int write_pointer(char buffer[], int index, int length,
		int width, int flags, char padd, char extra_c, int padd_start)
{
	int count = 0;
	
	if (!(flags & F_MINUS))
		while (--width >= length && ++count)
			write(1, &padd, 1);
	
	count += write(1, "0x", 2);
	while (padd_start && ++count && --index >= 0)
		write(1, &padd, 1);

	while (++index < BUFF_SIZE - 1)
	{
		if (buffer[index] == 'x')
			break;
		write(1, buffer + index, 1);
		count++;
	}

	write(1, &extra_c, 1);
	count++;
	
	while (width >= length && ++count)
	{
		write(1, &padd, 1);
		width--;
	}

	return (count);
}

/**
 * is_printable - Checks if a character is printable.
 * @c: The character to check
 * Return: 1 if printable, 0 otherwise
 */
int is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

/**
 * append_hexa_code - Appends the hexa code of a non-printable character.
 * @c: The non-printable character
 * @buffer: Buffer array to handle print
 * @index: Current index in the buffer
 * Return: Length of the hexa code
 */
int append_hexa_code(char c, char buffer[], int index)
{
	char map_to[] = "0123456789ABCDEF";

	buffer[index] = '\\';
	buffer[index + 1] = 'x';
	buffer[index + 2] = map_to[(c >> 4) & 0xF];
	buffer[index + 3] = map_to[c & 0xF];

	return (4);
}
