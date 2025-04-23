/*
*Aufgabe: Write a program to 'fold' long input lines into two or more shorter lines
*after the last nonblank charcter that occurs before the n-th column of input.
*Make sure your program does something intelligent with very long lines, and
*if there are no blanks or tabs before the specified column.
*/

#include <stdio.h>

#define MAXCOL 10 			/*maximum column of input*/
#define TABINC 8			/*tab increment size*/

char line[MAXCOL];			/*input line*/

int exptab (int);
int findblank (int);
int newpos (int);
void printl (int);

/*Fold long input lines into two or more shorter lines*/
int main(int argc, char const *argv[])
{
	int c, pos;

	pos = 0;				/*Position in the line*/
	while ((c = getchar()) != EOF)
	{
		line[pos] = c; 		/*store current character*/
		if (c == '\t')		/*expand the tab character*/
			pos = exptab(pos);
		else if (c == '\n')
		{
			printl(pos);	/*print current input line*/
			pos = 0;
		}
		else if (++pos >= MAXCOL)
		{
			pos = findblank(pos);
			printl(pos);
			pos = newpos(pos);
		}
	}
	return 0;
}

/*printl: print line until pos column*/
void printl (int pos)
{
	int i;

	for (i = 0; i < pos; ++i)
		putchar(line[i]);
	if (pos > 0)				/*any chars printed?*/
		putchar('\n');
}

/*exptab: expand tab into blanks*/
exptab (int pos)
{
	line[pos] = ' ';			/*tab is at least one blank*/

	for (++pos; pos < MAXCOL && pos % TABINC != 0; ++pos)
		line[pos] = ' ';

	if (pos < MAXCOL)			/*room left in current line*/
		return pos;
	else 						/*Current line is full*/
	{
		printl(pos);
		return 0;				/*reset current position*/
	}
}

/*findblank: find blanks' pstn*/
findblank (int pos)
{
	while (pos > 0 && line[pos] != ' ')
		--pos;
	if (pos == 0)		/*non blanks in the line?*/
		return MAXCOL;
	else				/*at least one blank*/
		return pos + 1;	/*position after the blank*/
}

/*newpos: rearrange line with new position*/
newpos (int pos)
{
	int i, j;

	if (pos <= 0 || pos >= MAXCOL)
		return 0;		/*nothing to rearrange*/
	else
	{
		j = 0;

		for (j = pos; j < MAXCOL; ++j)
		{
			line[i] = line[j];
			++i;
		}
		return i;		/*new position in line*/
	}
}