#include <stdio.h>

/* Prints Celsius - Fahrenheit table in reverse */

int main() {

	float celsius, fahr = 300;
	printf("Fahrenheit\tCelsius\n");
	for (; fahr >= 0; fahr = fahr - 20) {
		celsius = (5.0 / 9.0) * ( fahr - 32);
		printf("%3.0f\t\t%6.1f\n", fahr, celsius);
	}

	return 0;
}
