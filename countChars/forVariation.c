#include <stdio.h>

//2nd version
//count characters in Input

int main(int argc, char const *argv[])
{

double nc; //double float can handle numbers bigger than long

for (nc = 0; getchar() != EOF; ++nc)
  ;
printf("%.0f\n",nc);

}
