#include <stdio.h>

#define TABS 4			// default number of spaces to replace a tab
#define MAXLINE 1000		// maximum length of the input line

int get_line (char line[], int maxline);
void entab (char line[], int ntabs);

/*
 * main - program entry point
 * 
 * Return: 0 on success
 */
int main () {
	int len;		// length of the current input line
	char line[MAXLINE];	// current input line

	while ((len = get_line (line, MAXLINE)) > 0)
		entab (line, TABS);

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
 * entab - Replaces each of the ntabs consecutive spaces in the current input line  with a tab character
 * @line: The current input line
 * @ntabs: Number of spaces to be be replaced with a tab
 *
 * Return: Nothing
 */
void entab (char line[], int ntabs) {
	int c, next_c;		// a character in the input line
	int i, j, k;			// for loop iteration
	int tab_count, space_count;	// count of tabs and spaces to be printed respectively

	i = space_count = 0;
	while ((c = line[i]) != '\n' && c != '\0') {
		if (c == ' ') {
			++space_count;
		
			// check next char if its a space also
			j = i + 1;
			while ((next_c = line[j]) == ' ') {	// read all consecutive space characters
				++space_count;
				++j;
			}
		
			// print tabs + spaces based on the space count
			tab_count = space_count / ntabs;		// hopes this is integer division
			space_count = space_count % ntabs;

			for (k = 0; k < tab_count; ++k)
				putchar ('\t');
	
			for (k = 0; k < space_count; ++k)
				putchar (' ');

			i = j - 1;
		} else
			putchar(c);
	
		++i;			// Move to the next character
	}
	putchar('\n');
}	
