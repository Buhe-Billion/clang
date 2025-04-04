#include <stdio.h>

//copy input into output; 1st version

int main(int argc, char const *argv[])
{

int c;

while ((c = getchar()) != EOF)  // we had to put the assignment operation under () coz of operator precedence
  putchar(c);


}
