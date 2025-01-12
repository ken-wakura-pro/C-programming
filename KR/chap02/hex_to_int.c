#include <stdio.h>

int htoi (char s[]);

/*
 * htoi - converts a hexadecimal number to an int (decimal)
 * @s - A string representing the hexadecimal number
 *
 * Return: The Decimal hexadecimal equivalent of s
 * 	   if s is a valid hexadecimal number. 
 *	   Return -1 if s is contains invalid hexadecimal digit (s).
 */
int htoi (char s[]){
	int n;		// the integer equivalent of s
	int i;		// for loop iteration
	int c;		// a character in s
	int x;		// integer equivalent of a single digit in s

	// check if s starts with 0x or 0X
	if ((s[0] == '0') && (s[1] == 'x' || s[1] == 'X'))
		i = 2;		// skips first 2 characters
	else
		i = 0;

	n = 0;
	while ((c = s[i]) != '\0') {
		if (c >= '0' && c <= '9')
			x = c - '0';
		else if ((c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f')) {
			switch (c) {
				case 'a':
				case 'A':
					x = 10;
					break;
				case 'b':
				case 'B':
					x = 11;
					break;
				case 'c':
				case 'C':
					x = 12;
					break;
				case 'd':
				case 'D':
					x = 13;
					break;
				case 'e':
				case 'E':
					x = 14;
					break;
				case 'f':
				case 'F':
					x = 15;
					break;
			}
		} else {
			printf("Invalid hexadecimal character %c encountered\n", c);
			return -1;
		}

		n = n * 16 + x;
		++i;
	}

	return n;
}

/*
 * main - for testing htoi() function
 *
 * Return: 0 on success
 */
int main () {
	printf("1A3F is %d in decimal\n", htoi("1A3F"));
	printf("0xB7C2 is %d in decimal\n", htoi("OxB7C2"));
	printf("0X4f9D is %d in decimal\n", htoi("0X4f9D"));
	return 0;
}
