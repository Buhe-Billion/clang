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

/* Remove trailing blanks and tabs from character string s */
remove (char s[])
{
	int i;

	i = 0;
	while (s[i] != '\n')	/* Seek the new line character */
		++i;
	--i;					/* One back from '\n' */

	while ( i >= 0 && (s[i] == ' ' || s[i] == '\t') )
		--i;

	if ( i >= 0 )			/* Ensure that its a non blank line */
	{
		++i;
		s[i] = '\n';		/*	Reinstate newline character */
		++i;
		s[i] = '\0';		/* Terminate the string */
	}

	return i;
}