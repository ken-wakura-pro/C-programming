#include <stdio.h>

#define MAXLINE 1000	// maximum input line length
#define MAXLENGTH 80	// Maximum length of line to be printed

int get_line (char line[], int maxline);
void print_line (char line[]);

/*
 * main - program entry point
 *
 * Return: 0 on success
 */
int main () {
	int len;		// current line length
	char line[MAXLINE];	// current input line

	while ((len = get_line(line, MAXLINE)) > 0)
		if (len > MAXLENGTH)
			print_line(line);
	
	return 0;
}

/*
 * getline - read a line into s
 * @line: Line read from input
 * @lim: maximum input line length
 *
 * Return: The length of the line
 */
int get_line (char s[], int lim) {
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		i++;
	}

	s[i] = '\0';
	return i;
}

/*
 * print_line - prints the input line
 * @line: the line to be printed
 *
 * Return: Nothing
 */
void print_line (char line[]) {
	int i;
	
	i = 0;
	while (line[i] != '\0') {
		putchar(line[i]);
		i++;
	}
	
	putchar('\n');
}
