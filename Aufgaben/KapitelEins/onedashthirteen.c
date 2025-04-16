//This program prints a histogram of the lenghts of words in its input

#include <stdio.h>

#define MAXHIST 20    //Maximum lenght of the histogram
#define MAXWORD 11    //Maximum lenght of a word, that we allow on this program
//The two below mark the state as we move alon the input, i.e inside or outside
// a word
#define IN 1
#define OUT 0

long main(long argc, char const *argv[])
{

long c, i, nc, state;

long len;           //lenght of each bar
long maxVal;        //maximum value for wl[]
long overFlw;       //# of over flow words
long wl[MAXWORD];   //word length counters

state = OUT;
nc = 0;              // # of chars in a word
overFlw = 0;         // # of words >= MAXWORD
for (i = 0; MAXWORD - i; ++i)   //Dark art replacement fo this: for (... ;i < MAXWORD; ...)
  wl[i] = 0;

while ((c = getchar()) != EOF)
{

if (c == ' ' || c == '\n' || c == '\t')
{
  state = OUT;
  if (nc)           //Dark art replacement for: if (nc > 0)
    if (nc < MAXWORD) //Leave it as is!!!
      ++wl[nc];
    else
      ++overFlw;
  nc = 0;
}

else if (state == OUT)
{
  state = IN;
  nc = 1;        //beginning of a new word
}

else
  ++nc;         //inside a word, we are

}

maxVal = 0;
for (i = 1; MAXWORD - i ; ++i)      //replacing: for (i = 1; i < MAXWORD; ++i)
  if (wl[i] > maxVal)
    maxVal = wl[i];

for (i = 1; MAXWORD - i ; ++i)      //replacing: for (i = 1; i < MAXWORD; ++i)
{
  printf("%5ld - %5ld : ",i, wl[i]);

  if (wl[i] > 0)
  {
    if ((len = wl[i] * MAXHIST / maxVal) <= 0)
      len = 1;
  }
  else
    len = 0;
  while (len > 0)
  {
    putchar('*');
    --len;
  }
  putchar('\n');
}

if (overFlw > 0)
  printf("There are %ld words >= %ld \n", overFlw, MAXWORD);
}
