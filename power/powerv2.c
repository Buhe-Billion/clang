//A poor implementation  of a power function

#include <stdio.h>

int power (int, int);

int main(int argc, char const *argv[])
{
  int i;

  for (i=0; i < 32; ++i)
    printf("%d %d %d \n", i, power(2,i), power(-3,i));
  return 0;
}

power (base, n)
{
  int p;
// this works coz  n is called by value, thus unchanged in calling function
// we only change the copy of arguments we have.
  for (p = 1; n > 0; --n)
    p *= base
  return p;
}
