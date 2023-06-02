#include <stdio.h>

/**
 * main - print Fahrenheit - Celsius table in reverse
 *
 * Return: 0 (success)
 */

int main(void)
{
	int fahr;

	printf("Fahrenheit to Celsius table - Reverse\n");
	printf("***************************************\n");
	printf("Fahrenheit\t\tCelsius\n");

	for (fahr = 300; fahr >= 0; fahr -= 20)
		printf("%3d\t\t\t%6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
}
