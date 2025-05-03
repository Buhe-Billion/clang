#include "../collections/collections.h"
#include <stdio.h>
#include <string.h>

#define MAXLINES 5000	/* max #lines to be sorted */

char* lineptr[MAXLINES]; /* pointers to text lines */

/* sort input lines */
int main(int argc, char const *argv[])
{
	signed int nlines; /*number of input lines read*/

	if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
	{
		qsortv2(lineptr,0,nlines-1);
		writelines(lineptr,nlines);
		return 0;
	}

	else
	{
		printf("Error: input too big to sort.\n");
		return 1;
	}

}
/*It works!*/