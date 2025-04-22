#include "stdio.h"
#define MAXLINE 1000            //Maximum input size

//int getline (char line[], int maxline);
//int getline (char [], int );
int getline (char* , int);
//this program in its current state can only be compiled with the -std=c99
//Point being, that the latest compilers already have a definition for getline()
// -ansi doesn't work coz c++ comments (//) weren't yet implemented by then.


//void copy (char [], char []);
void copy (char*, char*);

//Print the longest input line
int main(int argc, char const *argv[])
{
  int len;                          //current line length
  int max;                          //maximum length seen so far
  char line[MAXLINE];               //current input line
  char longest[MAXLINE];            //longest line saved here

  max = 0;
  while ((len = getline(line, MAXLINE)) > 0)
    if (len > max)
    {
      max = len;
      copy(longest,line);
    }
    if (max > 0)
      printf("%s\n", longest);
      printf("This line is of length : %d characters\n", max);
  return 0;
}

//getline: read a line into s, and then return that lines length
getline (char s[], int lim)
{

  int c, i;

  for (i = 0; i < lim -1 && (c=getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if (c == '\n')
  {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';
  return i;

}

//copy: copy 'from' into 'to'; assume to is big enough
void copy(char to[], char from[])
{
  int i;

  i = 0;
  while ( ( to[i] = from[i] ) != '\0' )
    ++i;
}
