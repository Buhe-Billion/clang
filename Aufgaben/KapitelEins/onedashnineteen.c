/*
*Aufgabe: Write a function reverse(s) that reverses the character string s.
*Use it to write a program that reverses its input a line at a time.
*/

#include <stdio.h>
#define MAXLINE 1000		/* maximum input line size */

int getline (char* , int);
void reverse (char*);

/* reverse input lines, a line at a time */
int main(int argc, char const *argv[])
{
	char line[MAXLINE];		/* current input line */

	while ( getline(line,MAXLINE) > 0 )
	{
		reverse(line);
		printf("%s", line);
	}

	return 0;
}

/* reverse: reverse string s*/
void reverse (char s[])
{
	int i,j;
	char temp;

	i = 0;
	while (s[i] != '\0')		/*find the end of the string s*/
		++i;
	--i;						/*take one step back from '\0*/

	if (s[i] == '\n')
		--i;					/*Leave the new line character in place*/

	j = 0;
	while (j<i)
	{
		temp = s[j];
		s[j] = s[i];			/*swapping takes place here*/
		s[i] = temp;
		--i;
		++j;
	}
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