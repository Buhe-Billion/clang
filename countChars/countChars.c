#include <stdio.h>

//First version
//Count characters in Input

int main ()
{

long nc;

nc = 0;

while (getchar() != EOF)
	++nc;
printf("%ld\n",nc);

}
