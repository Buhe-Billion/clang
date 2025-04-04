#include <stdio.h>

//copy input into output; 1st version

int main(int argc, char const *argv[])
{

int c;

c = getchar();
while (c != EOF)
{

  putchar(c);
  c = getchar();

}

}
