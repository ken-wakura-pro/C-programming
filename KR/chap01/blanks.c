#include <stdio.h>

/* main - program entry point 
 * This function copies its input to its output, replacing each string
   of one or more blanks by a single blank.
 * Return: 0 on success
*/

int main() {
	int c;
	
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			while ((c = getchar()) == ' ')
				;	
			putchar(' ');
		}
			putchar(c);
	}

	return 0;
}

