#include "../../collections/collections.h"

static const char* pattern = "ould"; /* pattern to search for */

/* find all lines matching the pattern */

int main(int argc, char const *argv[])
{
	char line[MAXLINE];
	int found = 0;

	while (getline_(line,MAXLINE) > 0)
		if (strindex(line,pattern) >= 0)
		{
			printf("%s", line);
			found++;
		}
	return found;
}