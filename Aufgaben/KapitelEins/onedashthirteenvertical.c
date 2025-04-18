#include <stdio.h>

#define MAXHIST 20    //Max length of histogram
#define MAXWORD 11
#define IN 1
#define OUT 0

//print vertical histogram

int main(int argc, char const *argv[])
{

int c, i, j, nc, state;
int maxvalue;
int ovflow;
int wl[MAXWORD];

state = OUT;
nc = 0;
ovflow = 0;
for (i = 0; i < MAXWORD; ++i)
  wl[i] = 0;

while (( c = getchar() ) != EOF)
{

if (c == ' ' || c == '\n' || c == '\t')
{

  state = OUT;
  if (nc > 0)
    if (nc < MAXWORD)
      ++wl[nc];
    else
      ++ovflow;
  nc = 0;

}

else if (state == OUT)
{

  state = IN;
  nc = 1;

}

else
  ++nc;

}

maxvalue = 0;
for (i = 1; i < MAXWORD ; ++i)
  if (wl[i] > maxvalue)
    maxvalue = wl[i];



}
