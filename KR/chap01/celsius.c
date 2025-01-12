# include <stdio.h>

/* print Fahrenheit-Celsius table
*	for fahr - 0, 20, ... 300
*/

int main() {
	float fahr, celsius;	/* declare variable for fahrenheit and celsius */

	printf("%s\t%s\n", "Fahrenheit", "Celsius");
	for (fahr = 0; fahr <= 300; fahr =  fahr + 20) {
		celsius = (5.0/9.0) * (fahr - 32.0);
		printf("%3.0f\t\t%6.1f\n", fahr, celsius);
	}

	return 0;
}


