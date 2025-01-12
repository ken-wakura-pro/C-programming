#include <stdio.h>

#define MAXLINE 1000	// maximum input line length

int get_line (char line[], int maxline);
int get_start_index (char [], int len);
int get_end_index (char [], int len);

/*
 * main - program entry point
 *
 * Return: 0 on success
 * Removes trailing blanks and tabs from each line of input
 * and deletes entirely blank lines.
 */
int main () {
	int len;		// current line length
	char line[MAXLINE];	// current input line
	char new_line[MAXLINE];	// Current line without trailing whitespaces
	int i, start, end;		// start and end indices in the current line being copied

	// Read each line and get the start and end indices
	while ((len = get_line(line, MAXLINE)) > 0) {
		start = get_start_index (line, len);		// get the start index
		end = get_end_index (line, len);		// get the end index
		
		if ( start <= end) {
			for (i = start; i <= end; ++i)
				putchar(line[i]);
			putchar('\n'); // print newline after each line
		}
	}
		
	return 0;
}

/*
 * get_line - read a line into s, return length
 * @s: An array of characters that holds the characters in the line
 * @lim: Maximum length of the line
 *
 * Return: The length of the line
 */
int get_line (char s[], int lim) {
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/*
 * get_start_index - Get the position of the first non-whitespace character in the line
 * @line: the input line
 * @len: the length of the line
 *
 * Return: the position (index) of the first character (non-whitespace)
 */
int get_start_index (char line[], int len) {
	int c, i;

	for (i = 0; i < len; ++i) {
		c = line[i];
		if (c != ' ' && c != '\t') {
			return i;
		}
	}

	return i; 	// should never be executed
}

/*
 * get_end_index - Get the position of the last non-whitespace character in the line
 * @line: the input line
 * @len: the length of the line
 *
 * Return: the position (index) of the last character (non-whitespace)
 */
int get_end_index (char line[], int len) {
	int c;		// a character in the line
	int i;		// for loop iteration
	
	for (i = len - 1; i >= 0; --i)
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return i;
	return -1;
}
