#include <stdio.h>

/**
 * main -prints a histogram of lenghths of words in its input
 * Return: 0
 */
int main(void)
{
	int c;

	while ((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\t' || c == '\n')
			printf("\n");
		else
			printf("*");
	}

	return (0);
}
