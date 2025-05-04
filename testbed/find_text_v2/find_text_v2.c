#include "../../collections/collections.h"
#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

signed int getline_ (char*, int);

/* find: print lines that match pattern from 1st arg*/
int main(int argc, char const *argv[])
{
	char line[MAXLINE];
	signed int found = 0;

	if (argc != 2)
		printf("Usage: find pattern \n");

	else
		while (getline_(line, MAXLINE) > 0)
			if (strstr(line, argv[1]) != NULL)
			{
				printf("%s", line);
				found++;
			}
	
	return found;
}