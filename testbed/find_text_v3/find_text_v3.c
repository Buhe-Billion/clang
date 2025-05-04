#include "../../collections/collections.h"
#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

signed int getline_ (char*, int);

/* find: print lines that match pattern from 1st arg*/
int main(int argc, char const *argv[])
{
	char line[MAXLINE];
	signed long lineno = 0;
	signed int c, except = 0, number = 0, found = 0;

	while (--argc > 0 && (*++argv)[0] == '-')
		while (c = *++argv[0])
			switch (c)
				{
					case 'x':
						except = 1;
						break;
					case 'n':
						number = 1;
						break;
					default:
						printf("found: illegal option %c\n", c);
						argc = 0;
						found = -1;
						break;
				}

	if (argc != 1)
		printf("Usage: find -x -n pattern \n");

	else
		while (getline_(line,MAXLINE) > 0)
		{
			lineno++;
			if ((strstr(line, *argv) != NULL) != except)
			{
				if (number)
					printf("%ld:", lineno);
				printf("%s\n", line);
				found++;
			}
		}

	return found;

}