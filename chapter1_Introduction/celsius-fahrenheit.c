#include <stdio.h>

/**
 * main - print Celsius - Fahrenheit table
 *
 * Description: Prints the Celsius - Fahrenheit table
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

	printf("The Celsius - Fahrenheit Table\n");
	printf("**************************************\n\n");
	printf("Celsius\t\tFahrenheit\n");

	celsius = lower;
	while (celsius <= upper)
	{
		fahr = (9.0 / 5.0) * (celsius + 32.0);
		printf("%3.0f\t\t%6.2f\n", celsius, fahr);
		celsius  = celsius + step;
	}
}
