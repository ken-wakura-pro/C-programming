#include <stdio.h>

void squeeze (char s1[], char s2[]);
int any(char s1[], char s2[]);

/*
 * main - tests the squeeze function
 *
 * Return: 0 on success
 */
int main () {
	char s1[] = "Ken";
	char s2[] = "Wakura";
	printf("Ken + Wakura: ");
	squeeze(s1, s2);
	printf("%s\n", s1);

	printf("Wakura + Mbuya: ");
	char s3[] = "Wakura";
	char s4[] = "Mbuya";
	squeeze(s3, s4);
	printf("%s\n", s3);

	printf("\nTesting any()");
	char s5[] = "Ken";
	char s6[] = "Wakura";
	printf("Ken + Wakura: %d\n", any(s5, s6));

	char s7[] = "Wilson";
	char s8[] = "Amora";
	printf("Wilson + Amora: %d\n", any(s7, s8));

	return 0;
}

/*
 * squeeze - Deletes occurances of characters in s2 from s1
 * @s1: The first string
 * @s2:	The second string
 */
void squeeze (char s1[], char s2[]) {
	int c1, c2;		// a character in s1 and s2 respectively
	int i, j, k;		// for loop iteration
	int  match_found;	// true if a character in s2 matches a character in s1

	i = j = k = 0;

	for (i = 0; (c1 = s1[i]) != '\0'; ++i) {
		match_found = 0;
	
		for (j = 0; (c2 = s2[j]) != '\0'; ++j) {
			if (c1 == c2) {
				match_found = 1;
				break;
			}
		}
		
		if (!match_found)
			s1[k++] = s1[i];
	}
	s1[k] = '\0';
}

/*
 * any - returns the first location in a string s1 where any character
 *	 from the string s2 occurs.
 * @s1: The first string
 * @s2: The second string
 *
 * Return: first index of s1 with a matching character from s2
 * 	   Returns -1 if s1 contains no characters from s2
 */
int any(char s1[], char s2[]) {
	int c1, c2;
	int i, j;

	for (i = 0; (c1 = s1[i]) != '\0'; ++i)
		for (j = 0; (c2 = s2[j]) != '\0'; ++j)
			if (c1 == c2)
				return i;
	return -1;
}
