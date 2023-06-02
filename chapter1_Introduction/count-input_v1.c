#include <stdio.h>

/**
 * main - count characters in input (version 1)
 * Return: 0
 */

int main(void)
{
	long nc;

	nc = 0;
	while (getchar() != EOF)
		++nc;
	printf("%ld\n", nc);

	return (0);
}
