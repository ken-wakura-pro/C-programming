#include <stdio.h>

typedef enum {
	NORMAL,
	IN_SINGLE_COMMENT,
	IN_MULTI_COMMENT,
	IN_STRING,
	IN_CHAR
} State;

State current_state = NORMAL;
int paren_count = 0;
int bracket_count = 0;
int brace_count = 0;
int prev_c = 0;

/*
 * main - program entry point
 *
 * Return: 0 on success
 */
int main () {
	int c, next_c;
	
	next_c = getchar ();
	while ((c = next_c) != EOF) {
		next_c = getchar();
		switch (current_state) {
			case NORMAL:
				if (c == '/') {
					if (next_c == '/')
						current_state = IN_SINGLE_COMMENT;
					else if (next_c == '*')
						current_state = IN_MULTI_COMMENT;
				} else if (c == '"')
					current_state = IN_STRING;
				else if (c == '\'')
					current_state = IN_CHAR;
				else {
					switch (c) {
						case '(': ++paren_count; break;
						case '[': ++bracket_count; break;
						case '{': ++brace_count; break;
						case ')':
							--paren_count;
							if (paren_count < 0) {
								printf("Unmatched %c\n", ')');
								paren_count = 0;
							}
							break;
						case ']':
							--bracket_count;
							if (bracket_count < 0) {
								printf("Unmatched %c\n", ']');
								bracket_count = 0;
							}
							break;
						case '}':
							--brace_count;
							if (brace_count < 0) {
								printf("Unmatched %c\n", '}');
								brace_count = 0;
							}
							break;
					}
				}
				break;
			case IN_SINGLE_COMMENT:
				if (c == '\n')
					current_state = NORMAL;
				break;
			case IN_MULTI_COMMENT:
				if (c == '*' && next_c == '/')
					current_state = NORMAL;
				break;
			case IN_STRING:
				if (c == '"' && prev_c != '\\')
					current_state = NORMAL;
				break;
			case IN_CHAR:
				if (c == '\'' && prev_c != '\\')
					current_state = NORMAL;
				break;
		}
		prev_c = c;
	}
	
	// End of input: Final Checks
	
	// Counts non-zero
	if (paren_count > 0)
		printf("Unmatched %c\n", '(');
	if (bracket_count > 0)
		printf("Unmatched %c\n", '[');
	if (brace_count > 0)
		printf("Unmatched %c\n", '{');

	// Still in a comment or string
	switch (current_state) {
		case IN_SINGLE_COMMENT: 
			printf("Warning: Unterminated single-line comment\n");
			break;
		case IN_MULTI_COMMENT:
			printf("Warning: Unterminated multi-line comment\n");
			break;
		case IN_STRING:
			printf("Warning: Unterminated string\n");
			break;
		case IN_CHAR:
			printf("Warning: Unterminated character constant\n");
			break;
	}

	return 0;
}
