# Making Madlibs in C

### Team
MJ McMillen and Gracey Wilson

## Project Goal
Our goal is to increase our understanding of basic C concepts like character arrays and pointers by creating an interactive Make-Your-Own Madlib game. We also hope to practice building a code infrastructure/deciding how to divide a program into functions in a way that makes sense.

Our lower bound goal is to allow a user to choose between 5 madlibs and interface with the program through the command line. One idea for a stretch goal is to allow a user to input their email address at the end of the game and email themselves their madlib. We also have several other small features that we would like to implement to make the code more readable/efficient.

## How We Got Started

Our original idea was to make a “Choose Your Own Adventure” game, so we began by individually researching simple versions of this game in C. We pivoted from this idea because we realized we would end up spending more time on story development than on practicing our programming, and we had the opposite priorities for this project.

Once we decided on doing the madlibs, we scaffolded out the general code architecture with the necessary functions and added comments with their inputs and outputs, calling them in main(). Then we assigned each function to one of us as individuals, and set due dates for writing them in our Trello.

## What We're Doing Now

After brainstorming and roughly coding several different options for storing, printing, and editing our madlibs, we settled on our final code structure this past Sunday. Now we are writing those final functions.

We currently have three sample madlibs written, the print function written, and part of the command line interface written. Our program stores each madlib in its own character array. The character arrays have numbers where the users need to input a new word. The madlibs also have a corresponding key array. The key array has the part of speech that is needed to replace each of the numbers.

When the user starts the program they are prompted to pick a number between 1 and the number of madlibs we have written. The program will then request each of the parts of the speech found in the corresponding keywords array. The user types in their answers and the program stores them in a new array called answers. The answers array is passed to the print_madlib function.

The Print Madlib function takes in the answers and the number of madlib being done. It then cycles through the madlib character by character. It prints any character that is not a number and if it finds a number, it prints the corresponding word inputted by the user.

We’re going to make a stack diagram/code architecture diagram to better explain this.

## Next Steps
Our next steps mainly revolve around the user interface and madlib stories. We need to finish writing the user interface and hope to add the functionality so that a user can go through multiple madlibs without restarting the program. And we need to write more madlibs!

## Project Links
Repo: https://github.com/graceyw/SoftSysWAFFLES

Trello: https://trello.com/b/ssmb6u1g/waffles
