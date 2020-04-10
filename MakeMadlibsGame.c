/*
File: MakeMadlibsGame.c
Purpose: Allows a user to make their own madlib through an interactive game in the terminal.
Authors: MJ McMillen and Gracey Wilson
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER_OF_MADLIBS  4

// Madlib #1
char Mad1[60] = "The 1 NINJA said 2 to the 3 student to go 4 their homework.";

// Madlib #2
char Mad2[150] = "Professor of 1 at Olin College of 2 Allen Downey teaches a very 3 class called 4 Systems this spring.";

// Madlib #3
char Mad3[110] = "Head First 1 is a very 2 book about 3 oriented programming. The 2 book is as 4 as is it informative.";

// Madlib #4
char Mad4[110] = "Caches are 1 because they are 2 and close to the CPU, which minimizes 3 due to capacitance and 4 propagation.";

// Madlib library of pointers
char *Mad_List[NUMBER_OF_MADLIBS];
char master_key[4][4][35] =
{
  {"adjective", "adverb", "adjective", "verb"},
  {"capitalized plural noun", "capitalized verb ending in -ing", "adjective", "capitalized noun"},
  {"capital letter", "adjective", "noun", "adjective"},
  {"adjective", "adjective", "noun", "noun"}
};


void print_madlib(int num, char **answers)
/*
Takes in an int that describes the user-inputted number corresponding to the madlib they want to play, and a pointer to a 3D character array containing the words inputted by the user.
Prints the completed madlib with the user input inserted in the correct places of the madlib sentence.
*/
{
  int i;
  char m;
  printf("\nYour MadLib is... drumroll, please... \n\n");
  for (i=0; i<strlen(Mad_List[num-1]); i++)  // For the length of our madlib string...
  {
    m = Mad_List[num-1][i];                    // Grab the current character being processed
    if (atoi(&m) == 0)                         // If that character is not an integer...
    {
      printf("%c",m);                             // Then print the character
    }
    else if (m!= ' ')                          // If the current character is not a space (or an integer)
    {
      printf("%s", answers[(atoi(&m)-1)]);        // Then print the mth user-inputted word
    }
    else if (m==' ')                           // If the current character is a space
    {
      printf("%c",m);                             // Then print that space
    }
  }
  printf("\n\nThanks for playing! We hope you enjoyed your Madlib!\n");
}


int main()
/* Interacts with the user in the terminal using fgets prompts, collecting the user input and storing it in an array called answers.*/
  {
    Mad_List[0] = Mad1;
    Mad_List[1] = Mad2;
    Mad_List[2] = Mad3;
    Mad_List[3] = Mad4;

    char m = Mad_List[0][0];

    char input[15];
    char answers[4][15];
    int index;
    char madNum;
    int intmadNum;

    // User selects a madlib by number
    printf("Please enter an integer between 1 and %d to select a madlib to play: ", NUMBER_OF_MADLIBS);
    fgets(&madNum, 15, stdin);
    intmadNum = madNum-'0';

    // Collect and store user input for selected madlib
    for (int i=0; i<4; i++)
    {
      printf("Please enter a(n) ");                  // Prompt user input
      for (int r=0; r<35; r++)
      {                     // Print the letters stored in our 3d array
       printf("%c", master_key[intmadNum-1][i][r]);
      }
      printf(": ");
      fgets(input, 15, stdin);                // Collect user input via stdin and store in "input"
      for (int j=0; j<15; j++)                // For each character in the input word...
      {
        answers[index][j] = input[j];         // Add the inputted char to the answers array
      }
      index++;
    }

    char *rel_answers[4];
    for (int i=0; i<4; i++) {
      rel_answers[i] = answers[i];
    }

    print_madlib(intmadNum,rel_answers);   // Calls to print_madlib to print the final completed madlib
    return 0;
  }
