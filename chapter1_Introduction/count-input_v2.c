#include <stdio.h>

/**
 * main - count characters in input (version 1)
 * Return: 0
 */

int main(void)
{
	double nc;

	for (nc = 0; getchar() != EOF; ++nc)
		;
	printf("%.0f\n", nc);

	return (0);
}
