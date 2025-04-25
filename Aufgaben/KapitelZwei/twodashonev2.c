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
	/*
	printf("signed char min = %d\n", -(char)((unsigned char) ~0 >> 1) );
	printf("signed char max = %d\n", (char)((unsigned char) ~0 >> 1) );

	printf("signed short min = %d\n", -(short)((unsigned short) ~0 >> 1) );
	printf("signed short max = %d\n", (short)((unsigned short) ~0 >> 1) );

	printf("signed int min = %d\n", -(int)((unsigned int) ~0 >> 1) );
	printf("signed int max = %d\n", (int)((unsigned int) ~0 >> 1) );

	printf("signed long min = %ld\n", -(long)((unsigned long) ~0 >> 1) );
	printf("signed long max = %ld\n", (long)((unsigned long) ~0 >> 1) );
	*/
	printf("signed char min \t = \t %d  \t\t\tor in hex: \t%X\n", -(char)((unsigned char) ~0 >> 1), -(char)((unsigned char) ~0 >> 1));
	printf("signed char max \t = \t %d  \t\t\tor in hex: \t%X\n", (char)((unsigned char) ~0 >> 1), (char)((unsigned char) ~0 >> 1));

	printf("signed short min \t = \t %d  \t\tor in hex: \t%X\n", -(short)((unsigned short) ~0 >> 1), -(short)((unsigned short) ~0 >> 1));
	printf("signed short max \t = \t %d  \t\tor in hex: \t%X\n", (short)((unsigned short) ~0 >> 1), (short)((unsigned short) ~0 >> 1));

	printf("signed int min \t\t = \t %d  \t\tor in hex: \t%X\n", -(int)((unsigned int) ~0 >> 1), -(int)((unsigned int) ~0 >> 1));
	printf("signed int max \t\t = \t %d  \t\tor in hex: \t%X\n", (int)((unsigned int) ~0 >> 1), (int)((unsigned int) ~0 >> 1));

	printf("signed long min \t = \t %ld  \tor in hex: \t%lX\n", -(long)((unsigned long) ~0 >> 1), -(long)((unsigned long) ~0 >> 1));
	printf("signed long max \t = \t %ld  \tor in hex: \t%lX\n", (long)((unsigned long) ~0 >> 1), (long)((unsigned long) ~0 >> 1));


	/* unsigned types */
	/*
	printf("unsigned char max = %u\n", (unsigned char) ~0);
	printf("unsigned short max = %u\n", (unsigned short) ~0);
	printf("unsigned int max = %u\n", (unsigned int) ~0);
	printf("unsigned long max = %lu\n", (unsigned long) ~0);
	*/
	printf("unsigned char max \t = \t %u  \t\t\tor in hex: \t%X\n", (unsigned char) ~0, (unsigned char) ~0);
	printf("unsigned short max \t = \t %u  \t\tor in hex: \t%X\n", (unsigned short) ~0, (unsigned short) ~0);
	printf("unsigned int max \t = \t %u  \t\tor in hex: \t%X\n", (unsigned int) ~0, (unsigned int) ~0);
	printf("unsigned long max \t = \t %lu  \tor in hex: \t%lX\n", (unsigned long) ~0, (unsigned long) ~0);
	return 0;
}