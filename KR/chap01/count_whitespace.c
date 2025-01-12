#include <stdio.h>

/* count blanks, tabs and newlines in the input */

int main() {
	long b, t, n;		/* for counting blanks, tabs and newlines in the input respectively */
	int c;			/* the character read from input */

	b = 0; t = 0; n = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ') 
			b++;
		if (c == '\t')
			t++;
		if (c == '\n')
			n++;
	}
	
	printf("Number of blanks: %ld\n", b);
	printf("Number of tabs: %ld\n", t);
	printf("Number of newlines: %ld\n", n);

	return 0;
}

