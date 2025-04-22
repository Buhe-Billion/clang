/*
*Aufgabe: Write a program to remove trailing blanks and tabs from each line of input,
*and delete	entirely blank lines
*/

#include <stdio.h>
#define MAXLINE 1000		/* Max input line size */

int getline ( char*, int );
int remove ( char* );

/* Remove trailing blanks and tabs, and delete blank lines */
int main(int argc, char const *argv[])
{
	char line[MAXLINE];			/* Current input line */

	while ( getline(line,MAXLINE) > 0 )
		if ( remove(line) > 0 )
			printf("%s", line);
	return 0;
}