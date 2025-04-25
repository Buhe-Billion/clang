/*
*Aufgabe: Write a program to determine the ranges of char, short, int and long variables, both
*signed and unsigned, by printing the appropriate values from standard headers by direct 
*computation. Harder if you compute them: Determine the ranges of the various floating-point
*types.
*/

#include <stdio.h>

/* determine ranges of types */

int main(int argc, char const *argv[])
{
	/* signed types */
	printf("signed char min = %d\n", -(char)((unsigned char) ~0 >> 1) );
	printf("signed char max = %d\n", (char)((unsigned char) ~0 >> 1) );

	printf("signed short min = %d\n", -(char)((unsigned short) ~0 >> 1) );
	printf("signed short max = %d\n", (char)((unsigned short) ~0 >> 1) );

	printf("signed int min = %d\n", -(int)((unsigned int) ~0 >> 1) );
	printf("signed int max = %d\n", (int)((unsigned int) ~0 >> 1) );

	printf("signed long min = %ld\n", -(long)((unsigned long) ~0 >> 1) );
	printf("signed long max = %ld\n", (long)((unsigned long) ~0 >> 1) );

	/* unsigned types */
	printf("unsigned char max = %u\n", (unsigned char) ~0);
	printf("unsigned short max = %u\n", (unsigned short) ~0);
	printf("unsigned int max = %u\n", (unsigned int) ~0);
	printf("unsigned long max = %lu\n", (unsigned long) ~0);

	return 0;
}