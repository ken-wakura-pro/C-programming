#include <stdio.h>

/**
 * main - prints Fahrenheit - Celsius table
 *
 * Description: Print the Fahrenheit Celsius table
 * using for loop statement
 * Return: 0 always (success)
 */

int main(void)
{
	int fahr;

	printf("The Fahrenheit - Celsius Table\n");
	printf("******************************\n\n");
	printf("Fahrenheit\tCelsius\n");

	for (fahr = 0; fahr <= 300; fahr += 20)
		printf("%3d\t\t%6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));

	return (0);
}
