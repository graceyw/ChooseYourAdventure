#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LONGEST_PHRASE  50
#define LONGEST_WORD  15
#define NUMBER_OF_MADLIBS  3

// first Madlib
char Mad1[60] = "The 1 NINJA said 2 to the 3 students to 4 their homework.";
char key1[4][9] = {"adjective","adverb","adjective","verb"};
//char *key1p = key1;

// second Madlib
char Mad2[110] = "Allen Downey, Proffessor of 1 at Olin College of 2 is teaching a 3 class called 4 Systems this Fall.";
char key2[4][9] = {"noun","noun","adjective","noun"};
//char *key2p = key2;

// third Madlib
char Mad3[110] = "Head First 1 is a very 2 book about 3 oriented programming.The 2 book is as 4 as is it informitive.";
char key3[4][9] = {"letter","adjective", "noun","adverb"};
//char *key3p = key3;

//Madlib Library of pointers.
char *Mad_List[NUMBER_OF_MADLIBS-1];
char *Mad_Keys[NUMBER_OF_MADLIBS-1];

void print_madlib(int num, char **answers)
{
  int i;
  char m;
  printf("Your MadLib is ..... drumroll ... \n\n");
  for(i = 0; i < strlen(Mad_List[num-1]);i++)
  {
    m = Mad_List[num-1][i];
    if(atoi(&m)==0)
    {
      printf("%c",m);
    }
    else
    {
      printf("%s",answers[(atoi(&m)-1)]);
    }
  }
  printf("\n \n Thanks for Playing! We Hope you enjoyed your Madlib!");
}

int main()
  {
    Mad_List[0] = Mad1;
    Mad_List[1] = Mad2;
    Mad_List[2] = Mad3;
    Mad_Keys[0] = *key1;
    Mad_Keys[1] = *key2;
    Mad_Keys[2] = *key3;
    //char *mad_keys[NUMBER_OF_MADLIBS-1] = {key1p,key2p,key3p};
    char m= Mad_List[0][1];
    char k = Mad_Keys[0][1];
    printf("%c\n",k);
    char answers[4][10]={"large","smoothly","red","sprint"};
    char *rel_answers[4];
    rel_answers[0]=answers[0];
    rel_answers[1]=answers[1];
    rel_answers[2]=answers[2];
    rel_answers[3]=answers[3];
    print_madlib(1,rel_answers);
    return 0;
  }
