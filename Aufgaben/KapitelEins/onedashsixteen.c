/*
*Aufgabe: Revise the routine of the longest-line program so it will correclty
* print the length of arbitraryily long input lines and as much as possible of
*the text
*/

#include <stdio.h>
#define MAXLINE 1000          /* Maximum input line size */

int getline (char*, int);
void copy (char*, char*);

/*Print longest input line */
int main(int argc, char const *argv[])
{
  int len;            /*current line length */
  int max;            /*maximum length seen so far */
  char line[MAXLINE]; /*current input line */
  char longest[MAXLINE];/*longest line saved here */

  max = 0;
  while ( (len = getline(line,MAXLINE)) > 0 )
  {
    printf("The following line is of length: %d \nHere is said line: %s\n", len, line );
    if (len > max)
    {
      max = len;
      copy(longest,line);
    }
  }

  if (max > 0)        /*There was a line*/
    printf("This is the longest line of length %d\n%s", max, longest);
  return 0;
}

/* getline: read a line into s, return length */
getline (char s[], int lim)
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

/* copy: copy 'from' into 'to'; assume 'to' is big enough */
void copy (char to[], char from[])
{
  int i;

  i = 0;
  while ( (to[i] = from[i]) != '\0' )
    ++i;
}
