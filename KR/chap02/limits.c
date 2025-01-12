#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

long calc_limit (char type, int limit);
long calc_ulimit (char type);

/*
 * main - program entry point
 *
 * Return: Nothing
 *
 * Prints the ranges of `char`, `short`, `int` and `long`
 * variables, both `signed` and `unsigned`.
 */
int main () {
	// limits from standard header	
	printf("Limits from the standard header files:\n");
	printf("\n");

	printf("Signed char: %d to %d\n", CHAR_MIN, CHAR_MAX);
	printf("Unsigned char: %d\n", UCHAR_MAX);
	printf("\n");

	printf("Signed short: %d to %d\n", SHRT_MIN, SHRT_MAX);
	printf("Unsigned short: %d\n", USHRT_MAX);
	printf("\n");

	printf("Signed int: %d to %d\n", INT_MIN, INT_MAX);
	printf("Unsigned int: %d\n", UINT_MAX);
	printf("\n");

	printf("Signed long: %ld to %ld\n", LONG_MIN, LONG_MAX);
	printf("Unsigned long: %ld\n", ULONG_MAX);
	printf("\n");

	// limits from calculations
	printf("******************************************************************\n");
	printf("Limits from the calculations:\n");
	printf("\n");

	printf("Signed char: %ld to %ld\n", calc_limit('c', -1),calc_limit('c', 1));
	printf("Unsigned char: %ld\n", calc_ulimit('c'));
	printf("\n");

	printf("Signed short: %ld to %ld\n", calc_limit('s', -1), calc_limit('s', 1));
	printf("Unsigned short: %ld\n", calc_ulimit('s'));
	printf("\n");

	printf("Signed int: %ld to %ld\n", calc_limit('i', -1), calc_limit('i', 1));
	printf("Unsigned int: %ld\n", calc_ulimit('i'));
	printf("\n");

	printf("Signed long: %ld to %ld\n", calc_limit('l', -1), calc_limit('l', 1));
	printf("Unsigned long: %ld\n", calc_ulimit('l'));
	printf("\n");

	return 0;
}

/*
 * calc_limit - Calculates the limits of different integer types
 * @type: The integer type
 * @limit: -1 - minimum limit, 1 - maximum limit
 *
 * Return: The limits for the type
 */
long calc_limit (char type, int limit) {
	unsigned long nbytes, nbits;
	
	// get number of bytes using sizeof
	// get number of bits by multiplying  8 by number of bytes
	// calculate the limits -2^n-1 to 2^n-1 -1

	switch (type) {
		case 'c':
			nbytes = sizeof(char);
			break;
		case 's':
			nbytes = sizeof(short);
			break;
		case 'i':
			nbytes = sizeof(int);
			break;
		case 'l':
			nbytes = sizeof(long);
			break;
	}

	nbits = nbytes * 8;
	if (limit == -1)
		return -1 * ((long)pow(2, nbits-1));
	else
		return (long)pow(2, nbits-1) - 1;
}

/*
 * calc_ulimit - calculates the upper limit for unsigned integer types
 * @type: The unsigned integer type
 *
 * Return: the upper limit of the unsigned integer type
 */
long calc_ulimit (char type) {
	unsigned int nbytes, nbits;

	switch (type) {
		case 'c':
			nbytes = sizeof(char);
			break;
		case 's':
			nbytes = sizeof(short);
			break;
		case 'i':
			nbytes = sizeof(int);
			break;
		case 'l':
			nbytes = sizeof(long);
			break;
	}

	nbits = nbytes * 8;
	return (long) pow(2, nbits - 1) - 1;
}
