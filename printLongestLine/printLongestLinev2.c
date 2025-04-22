#include <stdio.h>

#define MAXLINE 1000		/* Define maximum input line size */

int max;					/* maximum length seen so far */
char line [MAXLINE];		/* current input line */
char longest [MAXLINE];		/* longest line saved here */

int getline (void);
void copy (void);

/* Print longest input line; specialised version */
int main(int argc, char const *argv[])
	{
		int len;
		extern int max;
		extern char longest[];

		max = 0;
		while ( (len = getline()) > 0 )
			{
				if (len > max)
				{
					max = len;
					copy();
				}
			}
		if (max > 0)		/* there was a line */
			printf("%s", longest);
		return 0;
	}

getline (void)
/*
*Glad to report that gcc -ansi defaults to int for fns
*but, I didn't manage to get it to work for args
*/
{
  int c, i, j;
  extern char line[];

  j = 0;
  for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
    if (i < MAXLINE - 2)
    {
      line[j] = c;       /* Line still in boundaries */
      ++j;
    }

    if (c == '\n')
    {
        line[j] = c;
        ++j;
        ++i;
    }

    line[j] = '\0';
    return i;
} 

/*copy: specialised version */
void copy (void)
{
	int i;
	extern char line[], longest[];

	i = 0;
	while ((longest[i] = line[i]) != '\0')
		++i;

}