#include <stdio.h>

/* main - program entry
 * Return 0 on success
 *
 * copy its input to output, replacing tabs with \t,
 * each backspace by \b, and each backslash by \\.
 */

int main() {
	int c;

	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			putchar('\\');
			putchar('t');
		} else if (c == '\b') {
			putchar('\\');
			putchar('b');
		} else if (c == '\\') {
			putchar('\\');
			putchar('\\');
		} else
			putchar(c);
	}

	return 0;
}

