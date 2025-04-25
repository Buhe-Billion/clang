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
	printf("signed char min \t = \t %d  \t\t\tor in hex: \t\t\t%x\n", SCHAR_MIN, SCHAR_MIN);
	printf("signed char max \t = \t %d  \tor in hex: \t\t\t%x\n", SCHAR_MAX, SCHAR_MAX);

	printf("signed short min \t = \t %d  \tor in hex: \t\t\t%x\n", SHRT_MIN, SHRT_MIN);
	printf("signed short max \t = \t %d  \tor in hex: \t\t\t%x\n", SHRT_MAX, SHRT_MAX);

	printf("signed int min \t\t = \t %d  \tor in hex: \t\t%x\n", INT_MIN, INT_MIN);
	printf("signed int max \t\t = \t %d  \tor in hex: \t\t%x\n", INT_MAX, INT_MAX);

	printf("signed long min \t = \t %ld  \tor in hex: \t%lx\n", LONG_MIN, LONG_MIN);
	printf("signed long max \t = \t %ld  \tor in hex: \t%lx\n", LONG_MAX, LONG_MAX);

	/* unsigned types*/
	printf("unsigned char max \t = \t %u  \tor in hex: \t\t\t%x\n", UCHAR_MAX, UCHAR_MAX);
	printf("unsigned short max \t = \t %u  \tor in hex: \t\t\t%x\n", USHRT_MAX, USHRT_MAX);
	printf("unsigned int max \t = \t %u  \tor in hex: \t\t%x\n", UINT_MAX, UINT_MAX);
	printf("unsigned long max \t = \t %lu  \tor in hex: \t%lx\n", ULONG_MAX, ULONG_MAX);

	return 0;
}