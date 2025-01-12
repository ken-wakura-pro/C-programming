#include <stdio.h>

#define IN 1	// Inside a word
#define OUT 0	// Outside a word

/* 
 * main - prints input one word per line
 * Return: 0 on success
 */

int main() {	
	
	int c, state;

	state = OUT;

	// Read input character by character
	while ((c = getchar()) != EOF) {
		// check if the character is a space, tab or newline
		if (c == ' ' || c == '\n' || c == '\t') {
			if (state == IN)
				putchar('\n');	// print a newline after a word
			state = OUT;		// we're outside a word now
		} else {
			if (state == OUT)
				state = IN;	// We've encountered the start of a word
	
			putchar(c);		// print the character
		}
	}

	return 0;
}
