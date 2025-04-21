//A poor implementation  of a power function

#include <stdio.h>



int main(int argc, char const *argv[])
{
  int i;

  for (i=0; i < 32; ++i)
    printf("%d %d %d \n", i, power(2,i), power(-3,i));
  return 0;
}
