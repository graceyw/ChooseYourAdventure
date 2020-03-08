/* Just trying an idea without messing up the main matlib mvp code.
- MJ
*/

#include <stdio.h>
#include <stdlib.h>

#define LONGEST_PHRASE = 50
#define LONGEST_WORD = 15
#define NUMBER_OF_MADLIBS = 3

// first Madlib
char Mad1[9][16] = {
                     "The ", "1", " NINJA said ", "3",
                     " to the ","3", " students to ", "4",
                     " their homework."
                    };
char key1[3][9] = {"adjective","adverb","adjective","verb"};
char *Mad1p = Mad1;
char *key1p = key1;

// second Madlib
char Mad2[9][30] = {
                                  "Allen Downey, Proffessor of ", "1", " at Olin College of ", "2",
                                  ", is teaching a ","3", " class called ", "4", " Systems this Fall."
                                };
char key2[2][9] = {"noun","noun","adjective","noun"};
char *Mad2p = Mad2;
char *key2p = key2;

// third Madlib
char Mad3[9][LONGEST_PHRASE] = {
                                  "Head First ", "1", " is a new book about ", "2",
                                  "oriented programming. The ","3", " book is as",
                                  "4", " as is it informitive."
                                };
char key3[3][9] = {"letter","noun","adjective","adverb"};
char *Mad3p = Mad3;
char *key3p = key3;


//Madlib Library of pointers.
char *mad_list[NUMBER_OF_MADLIBS] = [Mad1p,Mad2p,Mad3p];
char *mad_keys[NUMBER_OF_MADLIBS] = [key1p,key2p,key3p];


void print_madlib(int num, char *answers[][])
{
  /*
    Input: a number entered by the user.
    Output: a copy of the corresponding madlib with its placeholder words still intact.
  */
  //pipes answers into print.
  print &madlist[i]

}

int get_size(char a)
{
  /*
    Input: an array.
    Output: the size of the array (number of elements in it).
  */
  size_t n = sizeof(a) / sizeof(a[0]); //sizeof(a[0]) is just our buffer size
  return n
}


char parse_madlib(copyMad)
{
  /*
    Input: copyMad, a copy of the original madlib which contains words like "noun", "verb", "adjective", and "adverb"
    Output: an updated version of copyMad where all the "noun" etc. words have been replaced with user's input
  */
  for (int i=0; i<size(copyMad); i++) //write another func for determining size of madlib
  {
    if (copyMad[i] == "noun" || copyMad[i] == "verb")
    {
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
int main()
{
  int playing = 1;
  while (playing == 1)
  {

  int num = fgets("Type in a number: one or two "); //but does fgets return a pointer? need to do some testing here

  emptyMad = find_madlib(num);
  completedMad = parse_madlib(emptyMad);
  printf("%s\n", completedMad);
  }
  return 0;
}
