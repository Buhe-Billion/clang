// lets count blanks, tabs and new lines into separate values

#include <stdio.h>

int main(int argc, char const *argv[])
{

long character, blankCount, newLineCount, tabCount;  //declarations

tabCount = newLineCount = blankCount = 0;   //initiate with 0

while ( (character = getchar() != EOF) )
{
  if character == ' '
    ++blankCount;

  if character == '\n'
    ++newLineCount;

  if character == '\t'
    ++tabCount;
}

printf("spaces: %ld new_lines: %ld tabs: %ld\n",blankCount,newLineCount,tabCount);

}
