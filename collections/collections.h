/*
*Here I gather a common collction of utility functions of c programs.
*There may be many variations of a function, simply remove comments 
*from the version you prefer and comment out the rest.
*/

#include <stdio.h>
#include <stddef.h>

typedef unsigned char* byte_pointer;

/*From printLongestLinev2.c*/
int getline (void);
void copy (void);
/* from byte_representation.h */
void show_bytes ();
/* from atoi.h */
int atoi (char* );


#define MAXLINE 1000		/* Define maximum input line size */
int max;					/* maximum length seen so far */
char line [MAXLINE];		/* current input line */
char longest [MAXLINE];		/* longest line saved here */

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

/* from byte_representation.h */
/* typedef unsigned char* byte_pointer; */

void show_bytes (byte_pointer start, size_t len)
{
	int i;

	for (i = 0; i < len; i++)
		printf(" %.2x",start[i]);
	printf("\n");
}

/*atoi: convert s to integer */
int atoi (char s[])
{
	int i, n;

	n = 0;
	for (i = 0; s[i] >= '0' && 	s[i] <= '9'; ++i)
		n = 10 * n + (s[i] - '0');
	return n;
}