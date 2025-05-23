#include <stdio.h>

#define MAXHIST 20    //Max length of histogram
#define MAXWORD 11    //Max length of a word
#define IN 1          //inside a word
#define OUT 0         //outside a word

//print vertical histogram

int main(int argc, char const *argv[])
{

int c, i, j, nc, state;
int maxvalue;             //maximum value for wl[]
int ovflow;               //number of overflow words
int wl[MAXWORD];          //word length counter

state = OUT;
nc = 0;                   //number of chars in a word
ovflow = 0;               //number of words >= MAXWORD
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
  nc = 1;             //beginning of a new word

}

else
  ++nc;               //inside a word

}

maxvalue = 0;
for (i = 1; i < MAXWORD ; ++i)      //point of future review
  if (wl[i] > maxvalue)
    maxvalue = wl[i];

for (i = MAXHIST; i > 0; --i)       //point of future review
{

  for (j = 1; j < MAXWORD; ++j)           //point of future review
    if (wl[j] * MAXHIST / maxvalue >= i)  //point of future review
      printf(" * ");
    else
      printf("   ");
  putchar('\n');

}

for (i = 1; i < MAXWORD; ++i)           //point of future review
  printf("%4d ", i);
putchar('\n');

for (i = 1; i < MAXWORD; ++i)           //point of future review
  printf("%4d ", wl[i]);
putchar('\n');

if (ovflow > 0)
  printf("There are %d words >= %d \n", ovflow, MAXWORD);
}
//It works, but needs revision
//Check all the //point of future review comments
