/*
*Aufgabe: Write a program to determine the ranges of char, short, int and long variables, both
*signed and unsigned, by printing the appropriate values from standard headers by direct 
*computation. Harder if you compute them: Determine the ranges of the various floating-point
*types.
*/

#include <stdio.h>
#include <limits.h>

/* determine ranges of types */

int main(int argc, char const *argv[])
{
	/* signed types */
	printf("signed char min \t = \t %d\n", SCHAR_MIN);
	printf("signed char max \t = \t %d\n", SCHAR_MAX);

	printf("signed short min \t = \t %d\n", SHRT_MIN);
	printf("signed short max \t = \t %d\n", SHRT_MAX);

	printf("signed int min \t = \t %d\n", INT_MIN);
	printf("signed int max \t = \t %d\n", INT_MAX);

	printf("signed long min \t = \t %ld\n", LONG_MIN);
	printf("signed long max \t = \t %ld\n", LONG_MAX);

	/* unsigned types*/
	printf("unsigned char max \t = \t %u\n", UCHAR_MAX);
	printf("unsigned short max \t = \t %u\n", USHRT_MAX);
	printf("unsigned int max \t = \t %u\n", UINT_MAX);
	printf("unsigned long max \t = \t %lu\n", ULONG_MAX);

	return 0;
}