#include <stdio.h>

/*
 * main - Prints a histogram of the character count in its input
 * Return: 0 on success
 */
int main() {
	int c;		// for getting the character read from the input
	int i, j;	// for loop iteration
	int nchars[4];	// for storing character counts 

	for (i = 0; i < 4; i++)
		nchars[i] = 0;		// initialize array elements to 0

	while ((c = getchar()) != EOF) {
		if (c >= '0' && c <= '9')
			nchars[0]++;	// this is a digit
		else if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
			nchars[1]++;	// this is a letter
		else if (c == '\t' || c == ' ' || c == '\n')
			nchars[2]++;	// this is a whitespace (\t, ' ', or \n)
		else
			nchars[3]++;	// this is other special character
	}

	// Draw the histogram
	for (i = 0; i < 4; i++) {
		printf("%d ", i);
		for(j = 0; j <= nchars[i]; j++)
			printf("%c ", '|');
		printf("\n");
	}

	return 0;
}
