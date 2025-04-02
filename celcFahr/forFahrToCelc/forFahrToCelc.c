#include <stdio.h>

//print Fahr-Celc Tabell
int main(int argc, char const *argv[])
{

int fahr;

for (fahr = 0; fahr <= 300; fahr = fahr + 20)
  printf("%3d %6.1f\n",fahr, (5.0/9.0)*(fahr-32) );
}
