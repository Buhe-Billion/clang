//This programm prints one word, from its input, per line.

#include <stdio.h>

#define IN 1
#define OUT 0

int main(int argc, char const *argv[])
{

long character, state;

state = OUT;
while ((character = getchar()) != EOF)
{

  if ( character == ' ' || character == '\n' || character == '\t' )
  {
    if (state)
    {
      putchar('\n');
      state = OUT;
    }
  }

  else if (!state)
  {
    state == IN;
    putchar(character);
  }

  else putchar(character);
}

}
