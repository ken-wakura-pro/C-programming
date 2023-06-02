#include <stdio.h>

#define LOWER 0		/* Lower limit of the table */
#define UPPER 300	/* upper limit */
#define STEP 20		/* step size */

/**
 * main - Print Fahrenheit - Celsius table
 *
 * Description: Prints the Fahrenheit to Celsius table
 * using symbolic constants to define different constant
 * values in the program.
 * Symbolic constants make program more readable
 * Return: 0 always (success)
 */

int main(void)
{
	int fahr;

	printf("The Fahrenheit to Celsius Table\n");
	printf("*******************************\n\n");
	printf("Fahrenheit\tCelsius\n");

	for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
		printf("%3d\t\t%6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));

	return (0);
}
