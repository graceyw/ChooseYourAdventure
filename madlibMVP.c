/*  This file allows a user to interactively complete a madlib of their choice via the command line, and prints the completed madlib at the end.
    Authors: MJ McMillen and Gracey Wilson
*/

#include <stdio.h>
#include <stdlib.h>

char exampleMad[] = "The adjective NINJA said adverb to the adjective students to verb their homework.";

/*
  Input: a number entered by the user.
  Output: a copy of the corresponding madlib with its placeholder words still intact.
*/
char find_madlib(num) {
  // TODO MJ
  copyMad = copy(emptyMad); //copy doesn't actually work, must write it
  return copyMad;
}

/*
  Input: copyMad, a copy of the original madlib which contains words like "noun", "verb", "adjective", and "adverb"
  Output: an updated version of copyMad where all the "noun" etc. words have been replaced with user's input
*/
char parse_madlib(copyMad) {
  for (int i=0; i<size(copyMad); i++) { //write another func for determining size of madlib
    if (copyMad[i] == "noun" || copyMad[i] == "verb") {
      char *input = fgets("Please enter a %s \n", copyMad[i], 40, stdin);  //limits input string to arbitrary size. Should add an error in case it's bigger than that.
      copyMad[i] = input;
    }
  }
  return copyMad;
}

/*
  Prompts user to input a number, which corresponds to one of the madlibs. main() calls find_madlib() and parse_madlib() to find which madlib corresponds to the user's choice of number, and then parse it and prompt the user to replace the placeholder words like "noun" with the silly words of their choice.
  Finally, this function prints the completed madlib, completedMad.
*/
int main() {
  int num = fgets("Type in a number: one or two "); //but does fgets return a pointer? need to do some testing here
  emptyMad = find_madlib(num);
  completedMad = parse_madlib(emptyMad);
  printf("%s\n", completedMad);
  return 0;
}
