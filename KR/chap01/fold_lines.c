#include <stdio.h>

#define MAXLINE 1000		// maximum length of the input line

int get_line (char line[], int max_len);
void print_fold (char line[], int start_index, int end_index);
int get_end_index (char line[], int start_index, int fold_size, int len);
int get_first_char (char line[], int start_index, int fold_position);

/*
 * get_line - Read a line of input into a char array 'line'
 * @line: character array that stores the line read
 * @max_len: maximum length of the line to be  read
 *
 * Return: Length of the line read
 */
int get_line (char line[], int maxline) {
	int c, i;
	int max_len;
	
	for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}

/*
 * print_fold - prints a fold (a section of the line)
 * @line: Input line
 * @start_index: start index in the line to be printed
 * @end_index: End index in the line to be printed
 *
 * Return: Nothing
 * Assumes start_index and end_index are valid indices in the line
 */
void print_fold (char line[], int start_index, int end_index) {
	int i;		// for loop iteration
	
	for (i = start_index; i <= end_index; ++i) {
		printf("%c", line[i]);
	}
}

/*
 * get_end_index - gets the end index in the line fold to be printed
 * @line: The input line
 * @start_index: start index in this fold
 * @fold_size: Default fold size (Number of character to be printed in the fold
 * @len: Length of the line
 *
 * Return: The end index in the fold
 */
int get_end_index (char line[], int start_index, int fold_size, int len) {
	int end_index = start_index + fold_size;
	int i;

	// check if the fold fits within the line
	if (end_index >= len) 
		return len;

	// check if we can fold at a space or tab before the fold size
	for (i = end_index; i > start_index; --i)
		if (line[i] == ' ' || line[i] == '\t')
			return i;

	// if no space or tab is found, fold at the last non-blank character		return get_first_char(line, start_index, end_index);
}

/*
 * first_char - get the position of the character in a word to be folded
 * @line: input line
 * @start_index: start index in the fold
 * @fold_position: default fold position
 *
 * Return: New fold position - (position just before the first character in the word)
 */
int get_first_char (char line[], int start_index, int fold_position) {
	int i; 		// for loop iteration

	for (i = fold_position - 1; i >= start_index; --i)
		if (line[i] == ' ' || line[i] == '\t')
			return i;	// Return position just after the last non-blank character

	return fold_position; // if no non-blank character found, fold at the original position
}

/*
 * main - program entry point
 *
 * Return: Nothing
 */
int main () {
	char line[MAXLINE];		// current input line
	int len;			// Length of the input line
	int i;				// for loop iteration
	int fold_size;			// default max length of an output line
	int end_index;			// index of last character to be printed for a line

	fold_size = 49;
	i = 0;

	while ((len = get_line(line, MAXLINE)) > 0 ) {
		i = 0; 	// reset the start index for each new line

		while (i < len ) {
			end_index = get_end_index(line, i, fold_size, len);
			print_fold(line, i, end_index);
			putchar('\n');
			i = end_index;
		}
	}

	return 0;
}
