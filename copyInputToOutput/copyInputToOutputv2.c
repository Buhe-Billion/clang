#include <stdio.h>

//copy input into output; 1st version

int main(int argc, char const *argv[])
{

int c;

// we had to put the assignment operation under () coz of operator precedence
//The precedence of != is higher than that of =
/*
* so:
* while (c = getchar() != EOF)
* sets c to 0 or 1, depending on whether or not the call of getchar encountered end of file.
*/
while ((c = getchar()) != EOF)
  putchar(c);

}
