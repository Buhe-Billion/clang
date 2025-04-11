//Copy input to Output replacing each tab by \t, each backspace by \b, and each
//backslash by \\.Thus making tabs and backspaces unambigiously.

#include <stdio.h>

int main(int argc, char const *argv[])
{

long character;

while ((character = getchar()) != EOF)
  if (character == '\\')
    printf("\\\\");
  else if (character == '\b')
    printf("\\b");
  else if (character == '\t')
    printf("\\t");
  else putchar(character);
//And that's all she wrote
}
