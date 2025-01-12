#include <stdio.h>

int power(int base, int index);

/*
 * main - program entry point
 *
 * Return: 0 on success
 */
int main() {
	int m, n;

	// 6^2
	m = 6;
	n = 2;
	printf("%d raised to %d = %d\n", m, n, power(m, n));
	printf("\n");

	// 10^4
	m = 10;
	n = 4;
	printf("%d raised to %d = %d\n", m, n, power(m, n));
	printf("\n");

	//1000^5000
	m = 1000;
	n = 5000;
	printf("%d raised to %d = %d\n", m, n, power(m, n));
	printf("\n");
	
	return 0;
}

/*
 * power - calculates the exponent m raised to n
 * @m: The base
 * @n: The index
 *
 * Return: the exponent m raised to n on success
 */
int power(int m, int n) {
	int i, exponent;
	
	exponent = 1;
	for (i =  0; i < n; i++)
		exponent = exponent * m;

	return exponent;
}
