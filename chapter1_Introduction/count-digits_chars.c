#include <stdio.h>

/**
 * main - counts the number of occurence of characters
 * Description: Counts the number of occurences of each digit,
 * white space characters (blank, tab, newline),
 * and all other characters
 */
void main(void)
{
	int c, i, nwhite, nother;
	int ndigit[10];

	nwhite = nother = 0;
	for (i = 0; i < 10; ++i)
	{
		ndigit[i] = 0;
	}

	while ((c = getchar()) != EOF)
	{
		if (c >= '0' && c <= '9')
		{
			++ndigit[c - '0'];
		}
		else if (c == ' ' || c == '\n' || c == '\t')
		{
			++nwhite;
		}
		else
		{
			++nother;
		}
	}

	printf("digits = ");
	for (i = 0; i < 10; ++i)
		printf(" %d", ndigit[i]);
	printf(", white space = %d, other = %d\n", nwhite, nother);
}
