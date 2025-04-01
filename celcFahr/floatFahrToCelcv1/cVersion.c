#include <stdio.h>

/*
*Print Fahrenheit-Celcius table for fahr von 0 bis 300;
*floating point version
*/

int main(int argc, char const *argv[])
{
float fahr, celcius;
int lowerLimit, upperLimmit, stepSize;

lowerLimit = 0;
upperLimmit = 300;
stepSize = 20;

fahr = lowerLimit; //type conversion of the value from int to float!?
while (fahr <= upperLimmit) //type conversion
{
  celcius = (5.0/9.0) * (fahr-32.0);
  printf("%3.0f %6.2f\n",fahr, celcius);
  fahr = fahr + stepSize; //type conversion
}
}
