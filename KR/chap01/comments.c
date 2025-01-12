#include <stdio.h>

// Define the enum for program states
typedef enum {
	NORMAL,
	IN_SINGLE_COMMENT,
	IN_MULTI_COMMENT,
	IN_STRING,
	IN_CHAR
} State;

void handle_normal_state (int c, int next_c);
void handle_single_comment_state (int c);
int handle_multi_comment_state (int c, int next_c);
void handle_string_state (int c, int prev_c);
void handle_char_state (int c, int prev_c);

// Declare the current state variable globally
State current_state = NORMAL;

/*
 * handle_normal_state - detect transitions into comments,
 * 	double-quoted strings, single-quoted characters
 *	while printing non-comment characters
 *
 * @c: Current input character
 * @next_c: Next input character (peeked)
 *
 * Return: Nothing
 */
void handle_normal_state ( int c, int next_c) {
	if (c == '/' && next_c == '/')
		current_state = IN_SINGLE_COMMENT;
	else if (c == '/' && next_c == '*')
		current_state = IN_MULTI_COMMENT;
	else if (c == '"') {
		current_state = IN_STRING;
		putchar (c);
	} else if (c == '\\') {
		current_state = IN_CHAR;
		putchar (c);
	} else
		putchar (c);
}

/*
 * handle_single_comment_state - Ignore all characters until a newline (\n)
 * 	is encountered
 *
 * @c: Current input character
 *
 * Return: Nothing
 */
void handle_single_comment_state (int c) {
	if (c == '\n') {
		current_state = NORMAL;
		putchar (c);
	} else
		;
}

/*
 * handle_multi_comment_state - Ignore all characters until the closing
 * 	sequence is encountered
 *
 * @c: Current input character
 * @next_c: Next input character
 *
 * Return: Next input character
 */
int handle_multi_comment_state (int c, int next_c) {
	if (c == '*' && next_c == '/') {
		current_state = NORMAL;
		next_c = getchar();	// Move past '/'
	} else
		;			// Ignore 'c'
	return next_c;
}

/*
 * handle_string_state - Print characters inside a double-quoted string,
 * 	handling escaped quotes (\").
 *
 * @c: Current input character
 * @prev_c: Previous input character
 *
 * Return: Nothing
 */
void handle_string_state (int c, int prev_c) {
	putchar (c);

	if (c == '"' && prev_c != '\\')
		current_state = NORMAL;
}

/*
 * handle_char_state - Print characters inside a single-quoted character
 * 	and handle escaped quotes
 *
 * @c: Current input character
 * @prev_c: Previous input character
 *
 * Return: Nothing
 */
void handle_char_state (int c, int prev_c) {
	putchar (c);

	if (c == '\\' && prev_c != '\\')
		current_state = NORMAL;
}

/*
 * main - Program entry point
 *
 * Return: 0 on success
 */
int main () {
	int c, next_c, prev_c = 0;	// current, next && previous characters

	next_c = getchar();		// peek the first character

	while ((c = next_c) != EOF) {
		next_c = getchar ();			// peek next c

		switch (current_state) {
			case NORMAL:
				handle_normal_state (c, next_c);
				break;
			case IN_SINGLE_COMMENT:
				handle_single_comment_state (c);
				break;
			case IN_MULTI_COMMENT:
				next_c = handle_multi_comment_state (c, next_c);
				break;
			case IN_STRING:
				handle_string_state (c, prev_c);
				break;
			case IN_CHAR:
				handle_char_state (c, prev_c);
				break;
		}

		prev_c = c;
	}

	return 0;
}
