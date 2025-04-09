//create a copy that contracts multiple spaces into a single space

#define CHARACTERSEED 'Q'         //use this to initialise to a non-blank character
#include <stdio.h>

int main(int argc, char const *argv[])
{

long character, previousCharacter;

previousCharacter = CHARACTERSEED;
while ( (character = getchar()) != EOF )
/*
{
  if (character != ' ')
    putchar(character);
  else if (character == ' ')
    if (previousCharacter != ' ')
      putchar(character);
  previousCharacter = character;
}
*/

{
  if (character != ' ' || previousCharacter != ' ')
    putchar(character);
  previousCharacter = character;
}

}
