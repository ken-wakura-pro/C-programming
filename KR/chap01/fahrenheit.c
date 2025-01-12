# include <stdio.h>

/* Print Celsius - Fahrenheit table */

int main() {
	float fahr, celsius;
	
	printf("Celsius\tFahrenheit\n");
	for (celsius = 0; celsius <= 200; celsius = celsius + 20) {
		fahr = (9.0/5.0) * (celsius + 32);
		printf("%6.0f\t%3.1f\n", celsius, fahr);
	}
	
	return 0;
}
