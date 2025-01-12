#include <stdio.h>

#define IN 0
#define OUT 1

int main () {
	int c, i, j, char_count, state, max_chars;
	int nchars[30];			//stores number of words with specific number of characters

	// Assign default values to the array elements
	for (i = 0; i < 30; i++)
		nchars[i] = 0;
	
	
	state = OUT;
	char_count = 0;

	while ((c = getchar()) != EOF) {
		if (c == '\t' || c == ' ' || c == '\n') {
			if (state == IN) {			// end of a word
				nchars[char_count]++;
				state = OUT;
				char_count = 0;
			}
		} else {
			char_count++;
			state = IN;
		}
	}

	// Get the maximum number of characters
	max_chars = 0;
	for (i = 0; i < 30; i++)
		if (nchars[i] >= 1)
			max_chars = i;
	
	// Draw the histogram now since we have character counts
	for (i = 0; i <= max_chars; i++){
		printf("%d ", i);
		for (j = 0; j < nchars[i]; j++)
			printf("%c ", '|');
		printf("\n");
	}

	return 0;
}
