/*
*Here I gather a common collction of utility functions of c programs.
*There may be many variations of a function, simply remove comments 
*from the version you prefer and comment out the rest.
*/

/* Foundational set ups; start: */


#include <stdio.h>
#include <stddef.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>

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
void _strcat (char* , char* );
char* ptr__strcat (char* , char* );
void squeeze_str (char* ,char* );
int any (char* , char* );
unsigned getbits (unsigned , int, int);
unsigned setbits (unsigned , int, int, unsigned );
unsigned invert (unsigned , int , int );
unsigned rightrot (unsigned , int );
int wordlength (void);
unsigned _rightrot (unsigned, int );
int bitcount (unsigned);
int _bitcount (unsigned);
int binsearch (int, int* , int );
void escape (char* , char* );
void unescape (char* , char* );
void shellsort (int* , int);
void reverse (char* );
void expand (char* , char* );
void itoa (int, char* );

/* defines */


#define MAXLINE 1000		/* Define maximum input line size */


/* external variables */


int max;					/* maximum length seen so far */
char line [MAXLINE];		/* current input line */
char longest [MAXLINE];		/* longest line saved here */


/* Foundational set ups; end */




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

	/*
	n = 0;
	for (i = 0; isdigit(s[i]); ++i)
		n = 10 * n + (s[i] - '0');
	return n;
	*/

	int sign;

	for ( i = 0; isspace(s[i]); i++ )
		;

	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (n = 0; isdigit(s[i]); i++)
		n = 10 * n + (s[i] - '0');
	return sign * n;
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
	/*
	if ( c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
	*/

	return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c;
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

/* _strcat: concatenate t to the end of s; s must be big enough */
void _strcat (char s[], char t[] )
{
		int i, j;

		i = j = 0;
		while (s[i] != '\0')	/* find the end of s*/
			++i;
		/* copies even '\0' and then does the != comparison */
		while ((s[i++] = t[j++]) != '\0') /* copy t */
			;
}
/* ptr__strcat: concatenate t to the end of s; s must be big enough.
* Returns ptr to resultant string. 
*/
char* ptr__strcat (char s[], char t[] )
{
		int i, j;

		i = j = 0;
		while (s[i] != '\0')	/* find the end of s*/
			++i;
		/* copies even '\0' and then does the != comparison */
		while ((s[i++] = t[j++]) != '\0') /* copy t */
			;

		return s;
}


/*
*twodashfour
*Aufgabe: squeeze_str: Write an alternate version of squeeze that deletes each 
*character in s1 that matches any character in the string s2. 
*/
/* squeeze_str : delete each char in s1 which is in s2	*/
void squeeze_str (char s1[], char s2[] )
{
		int i, j, k;

		for ( i = k = 0; s1[i] != '\0'; i++)
		{
			for ( j = 0; s2[j] != '\0' && s2[j] != s1[i]; j++)
				;

			if (s2[j] == '\0')		/* end of string - no match */
				s1[k++] = s1[i];
		}

		s1[k] = '\0';
}

/*
*twodashfive
*Aufgabe: Write the function any(s1,s2), which returns the first location in the string
*s1 where any character from the string s2 occurs, or -1 if s1 contains no characters
*from s2. (The standard library function strpbrk does the same job but returns a pointer
* to the location.)
*/
/* any: return first location in s1 where any char from s2 occurs */
any (char s1[], char s2[] )
{
		int i, j;

		for (i = 0; s1[i] != '\0'; i++)
			for (j = 0; s2[j] != '\0'; j++)
				if (s1[i] == s2[j])		/* match found */
					return i;						/* location first match */

		return -1;								/* otherwise, no match */
}

/* getbits: get n bits from position p */
unsigned getbits (unsigned x, int p, int n)
{ return ( x >> (p+1-n)) & ~(~0 << n); }
/* 
*zB: getbits(x,4,3) returns the three bits in bit positions 4, 3 and 2, right adjusted
*/

/*
*twodashsix
*Aufgabe: Write a function setbits(x, p, n, y) that returns x with the n bits that begin
*at position p set to the rightmost n bits of y, leaving the other bits unchanged.
*/
/* setbits: set n bits of x at position p with bits of y */
unsigned setbits (unsigned x, int p, int n, unsigned y)
{ return x & ~(~(~0 << n) << (p+1-n)) | (y & ~(~0 << n)) << (p+1-n); }

/*
*twodashseven
*Aufgabe: Write a function invert (x,p,n) that returns x with the n bits that begin
*at position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others 
*unchanged.
*/
/* invert: inverts the n bits of x that begin at position p */
unsigned invert (unsigned x, int p, int n)
{ return x ^ (~(~0 << n) << (p+1-n)); }

/*
*twodasheight
*Aufgabe: Write a function rightrot(x,n) that returns the value of the integer x
*rotated to the right by n bit positions.
*/
/* rightrot: rotate x to the right by n positions */
unsigned rightrot (unsigned x, int n)
{
		int wordlength (void);
		int rbit;							/* right most bit */

		while (n-- > 0)
		{
			rbit = (x & 1) << (wordlength() - 1);
			x = x >> 1;				/* shift x 1 position right */
			x = x | rbit;			/* complete one rotation */
		}

		return x;
}

/* wordlength: computes word length of the machine */
int wordlength (void)
{
		int i;
		unsigned v = (unsigned) ~0;

		for (i = 1; (v = v >> 1) > 0; i++)
			;
		return i;
}

/* _rightrot: rotate x to the right by n positions */
unsigned _rightrot (unsigned x, int n)
{
	int wordlength(void);
	unsigned rbits;

	if ((n = n % wordlength()) > 0)
	{
		rbits	= ~(~0 << n) & x;	/* n rightmost bits of x */
														/* n rightmost bits to the left */

		rbits = rbits << (wordlength() - n);
		x = x >> n;							/* x shifted n positions to the right*/
		x = x | rbits;					/* rotation complete */
	}

	return x;
}

/* bitcount: count 1 bits in x */
int bitcount (unsigned x)
{
	int b;

	for (b = 0; x |= 0; x >> 1)
		if (x & 01)
			b++;
	return b;
}
/*
*Declaring the argument x to be unsigned ensures that when x is right shifted
*,vacated bits will be filled with 0s, not sign bits, regardless of the 
*machine the program is run on.
*/

/*
*twodashnine
*Aufgabe: In a two's complement number system, x &= (x-1) deletes the rightmost 
*1-bit in x. Explain why. Use this observation to write a faster version of
*bit-count.
*/
/* _bitcount: count 1 bits in x ; faster version */
int _bitcount (unsigned x)
{
		int b;

		for (b = 0; x != 0; x &= x-1)
			++b;
		return b;
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch (int x, int v[], int n)
{
		int low, mid, high;

		low = 0;
		high = n -1;
		while (low <= high)
		{
			 mid = (low+high) / 2;
			 if (x < v[mid])
			 	high = mid - 1;
			 else if (x > v[mid])
			 	low = mid + 1;
			 else /* found match */
			 	return mid;
		}

		return -1; /* no match */
}

/*
*threedashtwo
*Aufgabe: Write a function escape(s,t), that converts the newline and
*tab visible escape sequences like \n and \t as it copies the string t 
* to s. Use a switch. Write a function for the other direction as well
*converting escape sequences into the real characters.
*/

/* escape : expand newline and tab into visible sequences */
/* 			while copying the string t to s 									*/
void escape (char s[], char t[])
{
		int i, j;

		for (i = j = 0; t[i] != '\0'; i++)
			switch (t[i])
			{
					case '\n':
						s[j++] = '\\';
						s[j++] = 'n';
						break;

					case '\t':
						s[j++] = '\\';
						s[j++] = 't';
						break;

					default:
						s[j++] = t[i];
						break;					/* defensive programming */
			}

		s[j] = '\0';
}

/* unescape: convert escape sequences into real characters */
/* while copying the string t to s                         */
void unescape (char s[], char t[])
{
		int i, j;

		for (i = j = 0; t[i] != '\0'; i++)
			if (t[i] != '\\')
				s[j++] = t[i];

			else
				switch (t[++i])
				{
						case 'n':
							s[j++] = '\n';
							break;

						case 't':
							s[j++] = '\t';
							break;
						
						default:
							s[j++] = '\\';
							s[j++] = t[i];
							break;
						
				}

		s[j] = '\0';
}

/* shellsort : sort v[0] ... v[n-1] into increasing order */
void shellsort (int v[], int n)
{
		int gap, i, j, temp;

		for (gap = n/2; gap > 0; gap /= 2)
			for ( i = gap; i < n; i++ )
				for (j=i-gap; j >= 0 && v[j] > v[j+gap]; j -= gap)
				{
					temp = v[j];
					v[j] = v[j+gap];
					v[j+gap] = temp;
				}
}

/* reverse: reverse string s in place */
void reverse (char s[])
{
		int c, i, j;

		for ( i = 0, j = strlen(s) - 1; i < j; i++, j--)
			c = s[i], s[i] = s[j], s[j] = c;
}

/*
*threedashthree
*Aufgabe: Write a function expand(s1,s2) that expands shorthand notations 
*like a-z in the string s1 into the equivalent complete list abc...xyz in s2.
*Allow for letters of either case and digits, and be prepared to handle
*cases like a-b-c and a-z0-9 and -a-z.Arrange that a leading or trailing -
* is taken literally.
*/

/* expand: expand shorthand notation in s1 into the string s2 */
void expand (char s1[], char s2[])
{
		char c;
		int i,j;

		i = j = 0;
		while ((c = s1[i++]) != '\0') /* fetch a char from s1[] */
			if (s1[i] == '-' && s1[i+1] >= c)
			{
				i++;
				while (c < s1[i])					/* expand shorthand */
					s2[j++] = c++;
			}
			else 
				s2[j++] = c;							/* copy the character */

		s2[j] = '\0';
}

/* itoa : convert n to characters in s */
void itoa (int n, char s[])
{
		int i, sign;

		if ((sign = n) < 0)		/* record sign */
			n = -n;							/* make n positive */

		i = 0;
		/* generate digits in reverse order */
		do
			s[i++] = n % 10 + '0';		/* get the next digit */
		while ((n /= 10) > 0);			/* delete it */

		if (sign < 0)
			s[i++] = '-';
		s[i] = '\0';

		reverse(s);									/* double bang wow! */
}