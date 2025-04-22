#include "stdio.h"
#define MAXLINE 1000

//int getline (char line[], int maxline);
//int getline (char [], int );
int getline (char* , int);

//void copy (char [], char []);
void copy (char*, char*);

//Print the longest input line
int main(int argc, char const *argv[])
{
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  while ((len = getline(line, MAXLINE)) > 0)
    if (len > max)
    {
      max = len;
      copy(longest,line);
    }
    if (max > 0)
      printf("%s\n", longest);
  return 0;
}
