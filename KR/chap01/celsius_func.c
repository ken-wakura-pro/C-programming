# include <stdio.h>

float celsius(float fahr);

/*
 * main - print Fahrenheit-Celsius table
 *	for fahr - 0, 20, ... 300
 *
 * Return: 0 on success
 */

int main() {
	float fahr, c;	// declare variable for fahrenheit and celsius

	printf("%s\t%s\n", "Fahrenheit", "Celsius");
	for (fahr = 0; fahr <= 300; fahr =  fahr + 20) {
		c = celsius(fahr);
		printf("%3.0f\t\t%6.1f\n", fahr, c);
	}

	return 0;
}

/*
 * celsius - Converts the temperature fahr to degrees celsius
 * @fahr: the temperature in degrees fahrenheit
 *
 * Return: the temperature in degrees celsius
 */
float celsius(float fahr) {
	return (5.0/9.0) * (fahr - 32.0);
}
