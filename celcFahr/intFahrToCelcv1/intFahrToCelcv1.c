#include <stdio.h>

//This programm prints the integer values of the Fahrenheit-Celcius table for
//the range 0 bis 300 in Fahrenheit.
//check 1 2 3

int main(int argc, char const *argv[])
{
  int fahr, celcius;
  int lowerLimit, upperLimmit, stepSize;

  lowerLimit = 0;     //Lower limit of temperature table
  upperLimmit = 300;  //Upper limit of the table
  stepSize = 20;      //step size, wie genannt

  fahr = lowerLimit;
  while (fahr <= upperLimmit)
  {
    celcius = 5 * (fahr-32) / 9;
    //printf("%d\t%d\n", fahr, celcius);
    printf("%3d %6d\n",fahr, celcius); //right justified output
    fahr = fahr + stepSize;
  }

  return 0;
}
