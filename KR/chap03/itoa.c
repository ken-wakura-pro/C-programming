#include <stdio.h>

void reverse(char s[]);
int strlen_(char s[]);
void itoa(int n, char s[]);

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
}

/*
 * itoa - convert n to characters in s
 */
void itoa(int n, char s[]) {
	int i, sign;

	if ((sign = n) < 0)	// record sign
		n = -n;		// make n positive

	i = 0;
	do {	// generate the digits in reverse order
		s[i++] = n % 10 + '0';	// get next digit
	} while ((n /= 10) > 0);		// delete it

	if (sign < 0)
		s[i++] = '-';

	/*
	printf("i : %d\n", i);	
	while (i <= k) {
		s[i++] = ' ';
	}
	*/
	
	s[i] = '\0';
	reverse(s);
}

/*
 * main - Test the itoa function
 */
int main() {
	char buffer[100]; 	// buffer to store the result

	// Test cases
	itoa(255, buffer);
	printf("255, width 16: %s\n", buffer);

	itoa(-255, buffer);
	printf("-255, width 10: %s\n", buffer);

	/*
	itoa(255, buffer, 2);
	printf("255, width 2: %s\n", buffer);

	itoa(255, buffer, 8);
	printf("255, width 8: %s\n", buffer);

	*/
	return 0;
}
