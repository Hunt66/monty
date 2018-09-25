#include "holberton.h"

/**
 * read_textfile - renders the contents of a txt file to stdout
 * @filename: name of file to be read
 * @letters: char count to read
 *
 * Return: char count printed
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int file;
	char *tmp;
	ssize_t inchars, outchars;

	if (filename == NULL)
		return (0);

	file = open(filename, O_RDONLY);
	if (file == -1)
		return (0);

	tmp = malloc(letters);
	if (tmp == NULL)
		return (0);
	inchars = read(file, tmp, letters);
	if (inchars == -1)
		return (0);

	outchars = write(STDOUT_FILENO, tmp, inchars);
	if (outchars == -1)
		return (0);

	free(tmp);
	close(file);

	return (outchars);
}
