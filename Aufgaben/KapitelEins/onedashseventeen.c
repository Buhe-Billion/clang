/*
* Write a program to print all input lines that are longer than 80 characters.
*/

#include <stdio.h>
#define MAXLINE 1000    /* Maximum input line size */
#define LONGLINE 80     /* The line length we're looking for */

int getline (char*, int);

/* Print lines longer than than LONGLINE */

int main(int argc, char const *argv[])
{
  int len;             /* Current line length */
  char line[MAXLINE]; /* Currrent input line */

  while ( (len = getline(line, MAXLINE)) > 0 )
    if ( len > LONGLINE)
      printf("%s", line);

  return 0;
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
