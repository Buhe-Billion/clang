/*
*Aufgabe: Write a loop equivalent to the for loop below, ohne && oder || zu nutzen.
* for ( i =0; i < lim - 1 && (c=getchar()) != '\n' && c != EOF; ++i )
*	s[i] = c;
*/

#include <stdio.h>

enum loop {NO, YES};
enum loop okloop = YES;

void forloopreplacement (void)
{
	int i = 0;
	long lim = 1000L;
	int c;
	int s[lim];
	while (okloop == YES)

		if ( i >= lim -1 )		/* check bounds */
			okloop = NO;
		else if ( (c = getchar()) == '\n')
			okloop = NO;
		else if ( c == EOF )
			okloop = NO;
		else
		{
			s[i] = c;
			++i;
		}
}