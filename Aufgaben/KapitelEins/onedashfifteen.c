//Temperature conversion programm reformatted using functions

#include <stdio.h>

#define LOWER 0         //Lower limit of table
#define UPPER 300       //Upper limit of the table
#define STEP 20         //Step size

float celcius (float);

//print Fahrenheit-Celcius table
//for fahr = 0,20, ... ,300

int main(int argc, char const *argv[])
{
  float fahr;

  fahr = LOWER;
  while (fahr <= UPPER)
  {
    printf("%3.0f  %6.3f\n", fahr, celcius(fahr));
    fahr += STEP;
  }
  return 0;
}

//celcius: convert fahr into celcius
float celcius(float fahr)
{ return (5.0/9.0) * (fahr-32.0); }
