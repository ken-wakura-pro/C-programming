#include <stdio.h>
#include <stdbool.h>

void escape(char s[], char t[]);
bool is_escape_sequence (char c);
void escape_reverse(char s[], char t[]);

// define an enum to represent escape sequences
typedef enum {
	_ALERT = '\a',
	_BACKSPACE = '\b',
	_FORMFEED = '\f',
	_NEWLINE = '\n',
	_RETURN = '\r',
	_TAB = '\t',
	_VTAB = '\v',
	_BACKSLASH = '\\',
	_SINGLE_QUOTE = '\'',
	_DOUBLE_QUOTE = '\"',
	_QUESTION_MARK = '\?'
} EscapeSequence;

/*
 * escape - Replaces escape sequences in s with plain characters
 *
 * @s: First string with escape sequences
 * @: Array of chars that will contain characters in s
 *	with escape sequences replaced
 *
 * Return: Nothing
 * Assumption: t has enough space to hold all characters of s
 */
void escape(char s[], char t[]) {
	int i, j;		// for loop iteration

	i = j = 0;
	while (s[i] != '\0') {
		if (is_escape_sequence(s[i])) {
			t[j++] = _BACKSLASH;
			switch (s[i]) {
				case _ALERT: t[j++] = 'a'; break;
				case _BACKSPACE: t[j++] = 'b'; break;
				case _FORMFEED: t[j++] = 'f'; break;
				case _NEWLINE: t[j++] = 'n'; break;
				case _RETURN: t[j++] = 'r'; break;
				case _TAB: t[j++] = 't'; break;
				case _VTAB: t[j++] = 'v'; break;
				case _BACKSLASH: t[j++] = '\\'; break;
				case _SINGLE_QUOTE: t[j++] = '\''; break;
				case _DOUBLE_QUOTE: t[j++] = '\"'; break;
				case _QUESTION_MARK: t[j++] = '\?'; break;
			}
		} else 
			t[j++] = s[i];
		++i;
	}
	t[j] = '\0';	// Null terminate the output string
}

/*
 * is_escape_sequence - Checks if a character is an escape sequence
 * @c: The character being checked
 *
 * Return: true if c is and escape sequence, false otherwise
 * Assumption: Only handles escape sequences defined in the enum
 *	EscapeSequence defined above
 */
bool is_escape_sequence (char c) {
	switch (c) {
		case _ALERT:
		case _BACKSPACE:
		case _FORMFEED:
		case _NEWLINE:
		case _RETURN:
		case _TAB:
		case _VTAB:
		case _BACKSLASH:
		case _SINGLE_QUOTE:
		case _DOUBLE_QUOTE:
		case _QUESTION_MARK:
			return true;		// character is escape sequence
		default:
			return false;		// Not escape sequence
	}
}

/*
 * escape_reverse - reverses visible escape sequences in s
 *	into whitespace character escape sequences
 * @s: The first string
 * @t: The second string
 */
void escape_reverse (char s[], char t[]) {
	int i, j;	// loop indices
	int next_c;	// next character in s

	i = j = 0;
	while (s[i] != '\0') {
		if (s[i] == '\\') {	// peek the next character
			switch (s[i+1]) {
				case 'a': t[j++] = '\a'; break;
				case 'b': t[j++] = '\b'; break;
				case 'f': t[j++] = '\f'; break;
				case 'n': t[j++] = '\n'; break;
				case 'r': t[j++] = '\r'; break;
				case 't': t[j++] = '\t'; break;
				case 'v': t[j++] = '\v'; break;
				case '\\': t[j++] = '\\'; break;
				case '\'': t[j++] = '\''; break;
				case '\"': t[j++] = '\"'; break;
				case '\?': t[j++] = '\?'; break;
			}
			++i;
		} else 
			t[j++] = s[i];
		++i;
	}
	t[j] = '\0';
}

int main () {
	// declare strings for test case
	char s1[] = "Ken";		// No escape sequence
	char s2[] = "Ken	Wakura \nMbuya";
	char s3[] = "	";
	char s4[] = "";

	// declare t's. t can hold upto 100 chars only
	char t1[100];
	char t2[100];
	char t3[100];
	char t4[100];
	char t5[100];
	char t6[100];
	char t7[100];
	char t8[100];

	// Run the test cases
	escape(s1, t1);
	escape(s2, t2);
	escape(s3, t3);
	escape(s4, t4);

	printf("No escapes: %s\n", t1);
	printf("Couple of escapes: %s\n", t2);
	printf("Only escapes: %s\n", t3);
	printf("Empty string: %s\n", t4);

	escape_reverse(t1, t5);
	escape_reverse(t2, t6);
	escape_reverse(t3, t7);
	escape_reverse(t4, t8);
	printf("\nTesting Reverse\n");
	printf("t5: %s\n", t5);
	printf("t6: %s\n", t6);
	printf("t7: %s\n", t7);
	printf("t8: %s\n", t8);

	return 0;
}
