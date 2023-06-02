#include <stdio.h>

/**
 * main - print Fahrenheit - Celsius table
 *
 * Description: Prints the Fahrenheit - Celsius table
 * for fahr = 0, 20, ..., 300;
 * Return: 0 (Success)
 */

int main(void)
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0; /* lower limit of temperature table */
	upper = 300; /* upper limit of temperature table */
	step = 20; /* step size */

	printf("The Fahrenheit - Celsius Table\n");
	printf("**************************************\n\n");
	printf("Fahrenheit\tCelsius\n");

	fahr = lower;
	while (fahr <= upper)
	{
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("%3.0f\t\t%6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}
