# Make a Madlib!
## An interactive C game

### Team
MJ McMillen and Gracey Wilson

## Project Goal
Our goal was to increase our understanding of basic C concepts like character arrays and pointers by creating an interactive Make-Your-Own Madlib game. We also hoped to practice building a code infrastructure/deciding how to divide a program into functions in an efficient and readable way.

Our lower bound goal was to allow a user to choose between 3 Madlibs and interface with the program through the command line. One idea for a stretch goal was to allow a user to input their email address at the end of the game and email themselves their madlib. We also had several other small features that we were interested in implementing to make the code more readable and efficient.

## Learning Goals
Our learning goals for this project were very simple. We wanted to enforce good basic C coding habits and become more comfortable with the concept of pointers. We wanted to make sure we laid a good c foundation for the future. Before this project, when we were doing homework assignments, we often found ourselves using tricks like adding and deleting a bunch of * s until the code compiled. This showed we did not understand the basics of what was going on and we needed more practice with basic C principles.

## What We Did

We started out by thinking about code structure and how to solve the problem of inputting a user’s input into our original madlib. We considered using several formats/data structures including strings, arrays, and structs for our madlibs. At first, we planned and implemented our madlibs as arrays and had the words for the parts of speech such as “noun” or “adjective” directly within the array. Then there was also an array containing all the parts of speech. We made a copy of our madlib array (to preserve the original so that it could be played more than once) and for each word in the madlib array copy, we searched the parts-of-speech array to see if the word was a part of speech. If it was, we printed the word, asking the user to input a word of that part of speech. We then planned to replace the part of speech in the madlib array copy, with the user’s input.

However, as we realized when we wrote it all out like this and truly thought it through, this is a pretty slow way to solve the problem. It required us to malloc multi-dimensional arrays which isn’t great, and also made it more difficult to add new madlibs to our repertoire because we would need to make sure every part of speech was accounted for in our search function (which would also slow down the search function). So, back to the drawing board we went!

This time we prioritized thinking about clarity and efficiency. We brainstormed and came up with a new plan: store each madlib in its own character array. The character arrays have numbers instead of parts of speech, where the users will be prompted to input a new word. Each madlibs has a corresponding key array. The key array contains the parts of speech that must be inputted to replace each of the numbers.

When the user starts the program they are prompted to pick a number between 1 and the number of madlibs we have written. The program will then print each of the parts of the speech found in the corresponding keywords array (not iterating through the madlib array at all yet). The user types in their answers and the program stores them in a new array called answers. The answers array is then passed to the print_madlib() function, shown below.

```c
void print_madlib(int num, char **answers)
{
  int i;
  char m;
  printf("Your MadLib is ..... drumroll ... \n\n");
  for(i = 0; i < strlen(Mad_List[num-1]);i++) //For the length of our madlib string...
  {
    m = Mad_List[num-1][i];    //Grab the current character being processed
    if(atoi(&m)==0)       //If that character is not an integer...
    {
          printf("%c",m);    //Print the character
    }
    else
    {
          printf("%s",answers[(atoi(&m)-1)]);    //Else, print the mth user-inputted word
    }
  }
  printf("\n \n Thanks for playing! We hope you enjoyed your Madlib!");
}
```

The print_madlib function takes as arguments the user’s input (“answers”) and the madlib’s ID number. It then cycles through the madlib character by character. It prints any character that is not an integer and if it finds an integer, it prints the corresponding word in the “answers” array, as inputted by the user. When we’ve iterated over the entire array, the program prints a thank you statement and the game is over.

This system is much more efficient and logical than our first attempt. It’s important to acknowledge its limitations too, though, including the fact that no integers can be used as part of the story in the madlibs.


## Reflection

Our learning goals have remained consistent throughout the project - however, our ideas about how we would achieve those goals have changed quite a bit. At the start of the project, we planned to make a “Choose Your Own Adventure” game that enabled a user to make choices and end up with different outcomes. However, after researching more on the topic and beginning to write code, we realized this project would require more time developing the storyline than the code, which could be fun, but didn’t meet our learning goals as deeply. So, we practiced pivoting!

A few weeks later, this practice being flexible and adapting to unforeseen change became very useful. The school closed just when we started to make significant progress on the project and began accelerating past the finishing line towards stretch goals, but were severely limited in our ability to achieve said stretch goals with the loss of momentum. Therefore, due to circumstances beyond our control, this project ended up right at the level of our MVP - which we’re still pretty happy with.

This project effectively helped us achieve our learning goals. Through this project we became more comfortable writing C code. Before we started this project, we felt like when we wrote code in C, we were really writing poorly translated Python scripts. Now it feels like we have a grasp on the basic foundations of the language and are able to write code that truly takes better advantage of the opportunities and constraints of the language. It was a real “aha moment” when we started thinking in C.


## Project Links

Repo: https://github.com/graceyw/SoftSysWAFFLES

Trello: https://trello.com/b/ssmb6u1g/waffles
