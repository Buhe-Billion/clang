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

celcius = lowerLimit; //type conversion of the value from int to float!?
char* pointerToHeader = "CELCIUS    FAHR";
printf("%s\n",pointerToHeader); // %s expects argument of type char*
while (celcius <= upperLimmit) //type conversion
{
  fahr = (9.0 * celcius) / 5.0 + 32.0; // ((9*C)/5) + 32
  printf("%3.0f       %6.2f\n",celcius, fahr);
  celcius = celcius + stepSize; //type conversion
}
}
