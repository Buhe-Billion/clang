#include <stdio.h>

/*
// A declaration, without a definition leads to a linker error.
//long power (long m, long n);
long power (long, long);
*/

//test power function

int main(int argc, char const *argv[])
{
  long i;

  for (i=0; i < 300; ++i)
  //we get negative numbers for power(2,i)!!! Coz long is signed??
  //power(2,i) ends at 2 ^ 63 from 2 ^ 0; 0s after that
  //power(-3,i) continues to print values
    printf("%ld %ld %ld \n", i, power(2,i), power(-3,i));
  return 0;
}

/*
//power: raise base to n-th power; n >= 0
long power(long base, long n)
{
  long i, p;

  p = 1;
  for (i = 1; i <= n; ++i)
    p = p * base;
  return p;
}

//Bis dann
*/

//power: raise base to n-th power; n >= 0
//  In the style of old
