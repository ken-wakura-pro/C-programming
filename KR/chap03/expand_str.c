#include <stdio.h>
#include <stdbool.h>

bool isAlpha(char c);
bool isDigit(char c);
bool isAlphaNumeric(char c);
void expand(char s1[], char s2[]);

/*
 * isAlpha - Checks if c is an alphabet
 * @c: The character being checked
 *
 * Return: true if c is an alphabet, returns false otherwise
 */
bool isAlpha (char c) {
	return  ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/*
 * isDigit - checks if c is a digit
 * @c: The character being checked
 *
 * Return: true if c is a digit, returns false otherwise
 */
bool isDigit (char c) {
	return (c >= '0' && c <= '9');
}

/*
 * isAlphaNumeric - checks if c is alphanumeric
 * @c: Character being checked
 *
 * Return: true if c is alphanumeric, returns false otherwise
 */
bool isAlphaNumeric (char c) {
	return (isDigit(c) || isAlpha(c));
}

/*
 * isSameCategory - checks if two characters are of the same category
 * @a: First character
 * @b: Second character
 *
 * Return: True if a and b are of the same category
 * Same category means either both charecters are Numeric
 * or they are alphabets
 */
bool isSameCategory(char a, char b) {
	return (isAlpha(a) && isAlpha(b)) || (isDigit(a) && isDigit(b));
}

/*
 * expand - expands string s1 into string s2
 * @s1: First string
 * @s2: Second string
 *
 * Return: Nothing
 */
void expand(char s1[], char s2[]) {
	int i, j;		// loop indices
	int c, prev_c, next_c;	// current, previous and next characters in s1

	i = j = 0;
	while (true) {
		// get c
		c = s1[i];
		if (c == '\0') {	// we are at the end of the string s1
			s2[j] = c;	// Null-terminate the string s2
			break;
		}

		// get previous c
		if (i == 0)
			prev_c = 0;	// We are at the start of the string
		else
			prev_c = s1[i - 1];

		// get next_c
		next_c = s1[i + 1];

		// Check if we are in a collapsed sequence to be expanded
		if (c == '-' && isSameCategory(prev_c, next_c)){
			// expand the sequence
			if (prev_c < next_c)
				for (++prev_c; prev_c <= next_c; ++prev_c)
					s2[j++] = prev_c;
			else if (prev_c > next_c)
				for (--prev_c; prev_c >= next_c; --prev_c)
					s2[j++] = prev_c;
			else
				s2[j++] = next_c;
			++i; 	// advance to the next character after the sequence
		}
		else 
			s2[j++] = c;
		++i;
	}
}

/*
 * main - program entry point to test expand function
 *
 * Return: 0 on success
 */
int main () {
	char s1[] = "-aKenZ-A";
	char s2[1000];

	expand(s1, s2);
	printf("%s : %s\n", s1, s2);
}			
