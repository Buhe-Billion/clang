/*
*Aufgabe: Write a program to remove trailing blanks and tabs from each line of input,
*and delete	entirely blank lines
*/

#include <stdio.h>
#define MAXLINE 1000		/* Max input line size */

int getline ( char*, int );
int removeTrailingWhiteSpaces ( char* ); /* we changed the name from remove() coz that's defined under gcc -ansi */

/* remove trailing blanks and tabs, and delete blank lines */
int main(int argc, char const *argv[])
{
	char line[MAXLINE];			/* Current input line */

	while ( getline(line,MAXLINE) > 0 )
		if ( removeTrailingWhiteSpaces(line) > 0 )
			printf("%s", line);
	return 0;
}

/* remove trailing blanks and tabs from character string s */
removeTrailingWhiteSpaces (char s[])
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

/* getline: read a line into s, return length */
getline (char s[], int lim)
/*
*Glad to report that gcc -ansi defaults to int for fns
*but, I didn't manage to get it to work for args
*/
{
  int c, i, j;

  j = 0;
  for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
    if (i < lim - 2)
    {
      s[j] = c;       /* Line still in boundaries */
      ++j;
    }

    if (c == '\n')
    {
        s[j] = c;
        ++j;
        ++i;
    }

    s[j] = '\0';
    return i;
}