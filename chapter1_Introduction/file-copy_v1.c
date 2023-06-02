#include <stdio.h>

/**
 * main - copy input to output (version 1)
 *
 * Return: 0
 */

int main(void)
{
	int c;

	printf("This program copies its input to its output");
	printf(" one character at a time\n\n");

	printf("**************************\n");
	printf("**\t\t\t**\n");
	printf("**\tUSAGE\t\t**\n");
	printf("**\t\t\t**\n");
	printf("**************************\n\n");

	printf("file-copy_v1 < filename\n");

	c = getchar();
	while (c != EOF)
	{
		putchar(c);
		c = getchar();
	}
}
