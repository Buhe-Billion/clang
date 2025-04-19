#include <stdio.h>

int power (int m, int n);

//test power function

int main(int argc, char const *argv[])
{
  int i;

  for (i=0; i < 300; ++i)
    printf("%d %d %d \n", i, power(2,i), power(-3,i));
  return 0;
}
