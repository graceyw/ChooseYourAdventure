#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LONGEST_PHRASE  50
#define LONGEST_WORD  15
#define NUMBER_OF_MADLIBS  3

// first Madlib
char Mad1[60] = "The 1 NINJA said 2 to the 3 student to go 4 their homework.";
// char key1[4][15] = {"adjective", "adverb", "adjective", "verb"};

// second Madlib
char Mad2[500] = "Allen Downey, Professor of 1 at Olin College of 2 is teaching a 3 class called 4 Systems this Fall.";
// char key2[4][15] = {"noun", "noun", "adjective", "noun"};

// third Madlib
char Mad3[110] = "Head First 1 is a very 2 book about 3 oriented programming. The 2 book is as 4 as is it informative.";
// char key3[4][15] = {"letter", "adjective", "noun", "adverb"};


//Madlib Library of pointers.
char *Mad_List[NUMBER_OF_MADLIBS];
char master_key[3][4][15] = {{"adjective", "adverb", "adjective", "verb"},{"noun", "adverb", "adjective", "noun"},{"letter", "adjective", "noun", "adjective"}};
//char *Mad_Keys[NUMBER_OF_MADLIBS];

void print_madlib(int num, char **answers)
{
  int i;
  char m;
  printf("Your MadLib is... drumroll, please... \n\n");
  for(i = 0; i < strlen(Mad_List[num-1])+1;i++) // For the length of our madlib string...
  {
    m = Mad_List[num-1][i];    // Grab the current character being processed
    if(atoi(&m)==0)       // If that character is not an integer...
    {
      printf("%c",m);    // Print the character
    }
    else
    {
      printf("%s", answers[(atoi(&m)-1)]);    // Else, print the mth user-inputted word
    }
  }
  printf("\n\nThanks for playing! We hope you enjoyed your Madlib!\n");
}

int main()
  {
    Mad_List[0] = Mad1;
    Mad_List[1] = Mad2;
    Mad_List[2] = Mad3;


    char m = Mad_List[0][0];

    // HERE BEGINS the input/fgets stuff
    char input[15];
    char answers[4][15];
    int index;
    char madNum;
    int intmadNum;

    // User selects a madlib by number
    printf("Please enter an integer between 1 and %d to select a madlib to play: ",NUMBER_OF_MADLIBS);
    fgets(&madNum, 15, stdin);


    // We collect and store user input for selected madlib
    intmadNum = madNum-'0';
    printf("%d\n", intmadNum);
    for (int i=0; i<4; i++) {
      printf("Please enter a(n) "); //prompt user input
      for(int r = 0; r<15; r++){   //this for loop prints out the letters stored in our 3d array.
       printf("%c",master_key[intmadNum-1][i][r]);
      }
      printf("\n");
      fgets(input, 15, stdin);                   // Collect user input via stdin and store in "input" array
    //  printf("%s", input);                    // print statement for testing purposes
      for (int j=0; j<15; j++) {                 // For each character in the input word...
        answers[index][j] = input[j];            // Add the inputted char to the answers array
        // printf("%c", answers[index][j]);   // print statement for testing purposes
      }

      index++;
    }

    // char answers[4][10] = {"large","smoothly","red","sprint"};
    char *rel_answers[4];   // why do we have to make everything into rel_answers? why not just make the print_madlib call with answers? but if we do, we should make this a loop.
    rel_answers[0] = answers[0];
    rel_answers[1] = answers[1];
    rel_answers[2] = answers[2];
    rel_answers[3] = answers[3];
    print_madlib(intmadNum,rel_answers); // por que no solamente answers??
    return 0;
  }
