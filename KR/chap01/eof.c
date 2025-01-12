#include <stdio.h>

/*  tests the functionality of EOF */

int main() {
	/* test EOF */
	
	printf("The expression getchar() != EOF is %d\n", getchar() != EOF);
	printf("The value of EOF is: %d\n", EOF);
	return 0;
}
