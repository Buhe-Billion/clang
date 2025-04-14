#include <stdio.h>

//count digits, whitespace and other chars
long main(int argc, char const *argv[])
{

long c, i, nwhite, nother;
long ndigit[10];

nwhite = nother = 0;
for (i = 0; i < 10; ++i)
  ndigit[i] = 0;

while ((c = getchar()) != EOF)
  if (c >= '0' && c <= '9')
    ++ndigit[c - '0'];
  else if (c == ' ' || c == '\n' || c == '\t')
    ++nwhite;
  else ++nother;

printf("digits = ");
for (i = 0; i < 10; ++i)
  printf(" %ld",ndigit[i]);
printf(", whitespace = %ld, other = %ld\n",nwhite, nother);

}
