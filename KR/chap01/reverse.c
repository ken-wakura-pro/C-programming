#include <stdio.h>

#define MAXLINE 1000		// maximum length of the input line

int get_line(char line[], int maxline);
void reverse(char line[]);

/*
 * main - program entry point
 *
 * Return: 0 on success
 */
int main () {
	int len;		// length of the current line
	char line[MAXLINE];	// current input line
	
	while ((len = get_line (line, MAXLINE)) > 0) {
		reverse (line);
		putchar ('\n');
	}

	return 0;
}

/*
 * get_line - reads a line into s
 * @s: character array to store current line
 * @lim: maximum length of s
 *
 * Return: Lenght of the line s
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
 * reverse - reverses the characters in s
 * @s - input line
 *
 * Return: Nothing
 */
void reverse (char s[]) {
	int len, i;		// length of the line
	
	len = 0;
	// get the length of s
	while (s[len] != '\n' && s[len] != '\0')
		++len;
	
	// reverse s
	for (i = len - 1; i >= 0; --i)
		putchar(s[i]);

} 	
