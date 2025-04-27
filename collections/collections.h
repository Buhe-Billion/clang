/*
*Here I gather a common collction of utility functions of c programs.
*There may be many variations of a function, simply remove comments 
*from the version you prefer and comment out the rest.
*/

#include <stdio.h>
#include <stddef.h>
#include <limits.h>
#include <ctype.h>

/* type definitions */
typedef unsigned char* byte_pointer;
enum loop {NO, YES};
enum loop okloop = YES;


/* Function declarations of all the functions we have here */
int getline (void);
void copy (void);
void show_bytes ();
int atoi (char* );
void print_limits (void);
int lower (int);
int htoi(char* );
void squeeze (char* , int);


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
/* isdigit() is from <ctype.h> */
int atoi (char s[])
{
	int i, n;

	/*
	n = 0;
	for (i = 0; s[i] >= '0' && 	s[i] <= '9'; ++i)
		n = 10 * n + (s[i] - '0');
	return n;
	*/

	/*
	i = n = 0;
	while (okloop == YES)
		if (s[i] < '0')
			okloop = NO;
		else if (s[i] > '9')
			okloop = NO;
		else
		{
			n = 10 * n + (s[i] - '0');
			++i;
		}

	return n;
	*/

	n = 0;
	for (i = 0; isdigit(s[i]); ++i)
		n = 10 * n + (s[i] - '0');
	return n;
}

/* from twodashone.c */
void print_limits (void)
{
	/* signed types */
	printf("signed char min \t = \t %d  \t\t\tor in hex: \t%X\n", SCHAR_MIN, SCHAR_MIN);
	printf("signed char max \t = \t %d  \t\t\tor in hex: \t%X\n", SCHAR_MAX, SCHAR_MAX);

	printf("signed short min \t = \t %d  \t\tor in hex: \t%X\n", SHRT_MIN, SHRT_MIN);
	printf("signed short max \t = \t %d  \t\tor in hex: \t%X\n", SHRT_MAX, SHRT_MAX);

	printf("signed int min \t\t = \t %d  \t\tor in hex: \t%X\n", INT_MIN, INT_MIN);
	printf("signed int max \t\t = \t %d  \t\tor in hex: \t%X\n", INT_MAX, INT_MAX);

	printf("signed long min \t = \t %ld  \tor in hex: \t%lX\n", LONG_MIN, LONG_MIN);
	printf("signed long max \t = \t %ld  \tor in hex: \t%lX\n", LONG_MAX, LONG_MAX);

	/* unsigned types*/
	printf("unsigned char max \t = \t %u  \t\t\tor in hex: \t%X\n", UCHAR_MAX, UCHAR_MAX);
	printf("unsigned short max \t = \t %u  \t\tor in hex: \t%X\n", USHRT_MAX, USHRT_MAX);
	printf("unsigned int max \t = \t %u  \t\tor in hex: \t%X\n", UINT_MAX, UINT_MAX);
	printf("unsigned long max \t = \t %lu  \tor in hex: \t%lX\n", ULONG_MAX, ULONG_MAX);

}

/* from twodashonev2.c */
/* needs adjusting */

/*
void print_limits (void)
{
	/* signed types /
	
	printf("signed char min \t = \t %d  \t\t\tor in hex: \t%X\n", -(char)((unsigned char) ~0 >> 1), -(char)((unsigned char) ~0 >> 1));
	printf("signed char max \t = \t %d  \t\t\tor in hex: \t%X\n", (char)((unsigned char) ~0 >> 1), (char)((unsigned char) ~0 >> 1));

	printf("signed short min \t = \t %d  \t\tor in hex: \t%X\n", -(short)((unsigned short) ~0 >> 1), -(short)((unsigned short) ~0 >> 1));
	printf("signed short max \t = \t %d  \t\tor in hex: \t%X\n", (short)((unsigned short) ~0 >> 1), (short)((unsigned short) ~0 >> 1));

	printf("signed int min \t\t = \t %d  \t\tor in hex: \t%X\n", -(int)((unsigned int) ~0 >> 1), -(int)((unsigned int) ~0 >> 1));
	printf("signed int max \t\t = \t %d  \t\tor in hex: \t%X\n", (int)((unsigned int) ~0 >> 1), (int)((unsigned int) ~0 >> 1));

	printf("signed long min \t = \t %ld  \tor in hex: \t%lX\n", -(long)((unsigned long) ~0 >> 1), -(long)((unsigned long) ~0 >> 1));
	printf("signed long max \t = \t %ld  \tor in hex: \t%lX\n", (long)((unsigned long) ~0 >> 1), (long)((unsigned long) ~0 >> 1));


	/* unsigned types /
	
	printf("unsigned char max \t = \t %u  \t\t\tor in hex: \t%X\n", (unsigned char) ~0, (unsigned char) ~0);
	printf("unsigned short max \t = \t %u  \t\tor in hex: \t%X\n", (unsigned short) ~0, (unsigned short) ~0);
	printf("unsigned int max \t = \t %u  \t\tor in hex: \t%X\n", (unsigned int) ~0, (unsigned int) ~0);
	printf("unsigned long max \t = \t %lu  \tor in hex: \t%lX\n", (unsigned long) ~0, (unsigned long) ~0);
	return 0;
}
*/

/* lower: convert c to lower case; ASCII only */
/* this is a poorer, less portable version of tolower from <ctype.h> */
int lower (int c)
{
	if ( c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
}

/*
*twodashthree.c
*Aufgabe: htoi(s), which converts a string to hexadecimal digits 
*(including an optional 0x or 0X) into its equivalent integer value.The allowable
*digits are 0 through 9, a through f, and A through F.
*/
int htoi(char s[])
{
	int hexdigit, i, n;
	enum loop inhex;

	i = 0;
	if (s[i] == '0')	/*skip 0x/0X */
		++i;
		if (s[i] == 'x' || s[i] == 'X')
			++i;

	n = 0;	/* Int value to be returned */
	inhex = YES;	/* assume valid hex decimal */
	for ( ; inhex == YES; ++i)
	{
		if (isdigit(s[i]))
			hexdigit = s[i] -'0';
		else if ( s[i] >= 'a' && s[i] <= 'f' )
			hexdigit = s[i] - 'a' + 10;
		else if ( s[i] >= 'A' && s[i] <= 'F' )
			hexdigit = s[i] - 'A' + 10;
		else
			inhex = NO;			/* not a valid hexadecimal digit */

		if (inhex == YES)
			n = 16 * n + hexdigit;

	}
	
	return n;
}

/* squeeze: delete all c from s */
void squeeze (char s[], int c)
{
	int i, j;

	for (i = j = 0; s[i] != '\0'; i++)
		if (s[i] != c)
			s[j++] = s[i];		/* wow, this is beautifull */
	s[j] = '\0';
}