/*
*Aufgabe: Write a program to remove all comments from a C program. 
*Don't forget to handle quoted strings and character constants 
*properly. C comments do not nest. [!!! I tried to write an 
*ANSI comment within the comment below. I ended up proving that 
*C comments do not indeed nest!!!]
*/

/*
*We're looking for ANSI comments, like this one
*And not c++ style comments: //
*/



#include <stdio.h>

void rcomment (int);
void in_comment(void);
void echo_quote (int);

/* Remove all comments from a valid C programm */
int main(int argc, char const *argv[])
{
	int c, d;

	while ((c = getchar()) != EOF)
		rcomment(c);

	putchar('\n'); /* new line at the end of the output*/
	return 0;
}

/*rcomment: read each character, remove the comments*/
void rcomment (int c)
{
	int d;

	if (c == '/')
		if ((d = getchar()) == '*')
			in_comment();			/*beginning comment*/
		else if ( d == '/')
		{
			putchar(c);				/*another slash*/
			rcomment(d);
		}
		else
		{
			putchar(c);				/* not a comment*/
			putchar(d);
		}
	else if (c == '\'' || c == '"')	/*beginning of a quote*/
		echo_quote(c);
	else 
		putchar(c);					/*not a comment*/
}

/*in_comment: inside a valid comment*/
void in_comment (void)
{
	int c, d;

	c = getchar();	/*prev character*/
	d = getchar();	/*current character*/

	while ( c != '*' || d != '/')	/*search for end*/
	{
		c = d;
		d = getchar();
	}
}

/*echo_quote: echo characters within quotes */
void echo_quote (int c)
{
	int d;

	putchar(c);
	while ( (d = getchar()) != c) /* search for end*/
	{
		putchar(d);
		if (d == '\\')
			putchar(getchar()); /*ignore escape sequence*/
	}
	
	putchar(d);
}