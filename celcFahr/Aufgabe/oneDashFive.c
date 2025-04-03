#include <stdio.h>

#define LOWERLIMIT 0
#define UPPERLIMIT 300
#define STEPSIZE 20

int main(int argc, char const *argv[])
{

  int fahr;
  //this loop stops at fahr = 20; and I thought loops terminated at negative
  //numbers, but it seems to be that they terminate at the 1st non positive number!!
  //for (fahr = UPPERLIMIT; fahr ; fahr -= 20)
  for (fahr = UPPERLIMIT; fahr >= LOWERLIMIT; fahr -= STEPSIZE)
    printf("%3d %6.1f\n",fahr, (5.0/9.0)*(fahr-32) );

}
