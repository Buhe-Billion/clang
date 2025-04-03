#include <stdio.h>

#define LOWERLIMIT 0
#define UPPERLIMIT 300
#define STEPSIZE 20

int main(int argc, char const *argv[])
{

  int fahr;

  for (fahr = UPPERLIMIT; fahr ; fahr -= 20)
    printf("%3d %6.1f\n",fahr, (5.0/9.0)*(fahr-32) );

}
