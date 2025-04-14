//This programm prints one word, from its input, per line.

#include <stdio.h>

#define IN 1
#define OUT 0

//Get input and print one word per line from it.
int main(int argc, char const *argv[])
{

long character, state;    //I chose long for a wide data type;
                          //definitely not necessary

state = OUT;
while ((character = getchar()) != EOF)
{

  if ( character == ' ' || character == '\n' || character == '\t' )
  {
    if (state)
    {
      putchar('\n'); //finish the word with a line termination
      state = OUT;
    }
  }

  else if (!state)
  {
    state = IN;             //here we're at the beginning of a word
    putchar(character);
  }

  else putchar(character);    //here, we're inside of a word
}

}
