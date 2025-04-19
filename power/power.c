#include <stdio.h>

// A declaration, without a definition leads to a linker error.
//long power (int m, int n);
long power (int, int);

//test power function

int main(int argc, char const *argv[])
{
  long i;

  for (i=0; i < 300; ++i)
    printf("%ld %ld %ld \n", i, power(2,i), power(-3,i));
  return 0;
}

//power: raise base to n-th power; n >= 0
long power(long base, long n)
{
  long i, p;

  p = 1;
  for (i = 1; i <= n; ++i)
    p = p * base;
  return p;
}
