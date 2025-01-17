#include <stdio.h>

void reverse(char s[]);
void itob(int n, char s[], int b);
int strlen_(char s[]);

/*
 * itob - Converts the integer n to a string representation in base b
 * @n: The integer to convert
 * @s: The string to store the result
 * @b: The base for conversion (e.g. 2, 10, 16 ...)
 *
 * Return: Nothing
*/
void itob(int n, char s[], int b) {
	int i = 0;		// index for the string
	int isNegative = 0;	// Flag for negative numbers (base 10 only)
	int digit;		// a digit in n

	// Handle negative numbers for base q0
	if (n < 0 && b == 10) {
		isNegative = 1;
		n = -n;		// convert to positive
	}

	// Convert n to a given base
	do {
		digit = n % b;
		s[i++] = (digit > 9) ? (digit - 10 + 'A') : (digit + '0');
		n /= b;
	} while (n > 0);

	// Add '-' for negative numbers in base 10
	if (isNegative)
		s[i++] = '-';

	// Null-terminate s
	s[i] = '\0';

	// Reverse s to get the correct order of the string
	reverse(s);
}

/*
 * reverse - Reverses the characters in a string s in place
 * @s: The string to reverse
 *
 * Return: Nothing
 */
void reverse(char s[]) {
	int len;	// length of s
	int i, j;	// for loop iteration
	char temp;	// a character in s (temporary)

	len = strlen_(s);
	for (i = 0, j = len - 1; i < j; i++, j--) {
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}

/*
 * strlen_ - calculates the length of a string s
 * @s: The string whose length is to be found
 *
 * Return: The number of character in the string s
 */
int strlen_(char s[]) {
	int i = 0;

	while (s[i++] != '\0')
		;
	return i - 1;
	printf("length of s: %d\n", i);
}

/*
 * main - Test the itob function
 */
int main() {
	char buffer[100]; 	// buffer to store the result

	// Test cases
	itob(255, buffer, 16);
	printf("255 in base 16: %s\n", buffer);

	itob(-255, buffer, 10);
	printf("-255 in base 10: %s\n", buffer);

	itob(255, buffer, 2);
	printf("255 in base 2: %s\n", buffer);

	itob(255, buffer, 8);
	printf("255 in base 8: %s\n", buffer);


	return 0;
}
