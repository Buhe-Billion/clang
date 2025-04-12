//Let us define a word such that it is any sequence of characters that does not
//contain a blank, tab or new line.
//Please note that there exists already a sophisticated UNIX implementation: wc

#include <stdio.h>

#define IN 1        //Sate: Inside a word
#define OUT 0       //State: Outside a word

//count lines, words and characters in input
