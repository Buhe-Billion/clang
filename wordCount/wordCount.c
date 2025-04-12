//Let us define a word such that it is any sequence of characters that does not
//contain a blank, tab or new line.
//Please note that there exists already a sophisticated UNIX implementation: wc

#include <stdio.h>

#define IN 1        //Sate: Inside a word
#define OUT 0       //State: Outside a word

//count lines, words and characters in input
int main(int argc, char const *argv[])
{

long c, nl, nw, nc, state;

state = OUT;
nl = nw = nc = 0;

while ((c = getchar()) != EOF)
{
  ++nc;

  if (c == '\n')
    ++nl;

  if (c == ' ' || c == '\n' || c == '\t')
    state = OUT;

  else if (!state)
  {
    state = IN;
    ++nw;
  }
}

printf("LineCount: %ld \t WordCount: %ld \t CharacterCount: %ld \n", nl, nw, nc);

}
