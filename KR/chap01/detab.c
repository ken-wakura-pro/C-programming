#include <stdio.h>

#define TABS 4			// default number of spaces to replace a tab
#define MAXLINE 1000		// maximum length of the input line

int get_line (char line[], int maxline);
void detab (char line[], int ntabs);

/*
 * main - program entry point
 * 
 * Return: 0 on success
 */
int main () {
	int len;		// length of the current input line
	char line[MAXLINE];	// current input line

	while ((len = get_line (line, MAXLINE)) > 0)
		detab (line, TABS);

	printf("\n");		// just in case there is not newline at the end
	return 0;
}

/*
 * get_line - Reads a line of input into char array 'line'
 * @line: Character array that stores the line read
 * @max_len: Maximum length of the line read
 *
 * Return: Length of the line read
 */
int get_line (char line[], int max_len) {
	int c, i;

	for (i = 0; i < max_len -1 && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}

/*
 * detab - Replaces all tabs in the line with ntabs spaces
 * @line: The current input line
 * @ntabs: Number of spaces to replace tabs
 *
 * Return: Nothing
 */
void detab (char line[], int ntabs) {
	int c;		// a character in the line
	int i, j;	// for loop iteration

	i = 0;
	while ((c = line[i]) != '\n' && c != '\0') {
		if (c == '\t')
			for (j = 0; j < ntabs; ++j)
				putchar (' ');
		else
			putchar (c);
		++i;
	}
	putchar ('\n');
}
