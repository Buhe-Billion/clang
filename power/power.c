#include <stdio.h>

// A declaration, without a definition leads to a linker error.
//int power (int m, int n);
int power (int, int)

//test power function

int main(int argc, char const *argv[])
{
  int i;

  for (i=0; i < 300; ++i)
    printf("%d %d %d \n", i, power(2,i), power(-3,i));
  return 0;
}
