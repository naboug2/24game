Description:

24 is a math game, in which the player is presented with 4 numbers and they must
determine a way to combine those numbers using mathematical operations to get 24 as
the result. Each number must be used, and each number can be used only once.

See https://www.24game.com/t-about-howtoplay.aspx for more information.

This following is a C program that allows the user to play a simplified version of this
game. The user can only use addition (+), subtraction (-), multiplication (*), and division
(/). The four numbers presented in each puzzle are all single digits (numbers 1-9). The
user does not need to use all four mathematical operations.

The calculation for the result is done in sequential order on the numbers, which are also
used in order. For instance, if the numbers are 3, 9, 4, 1 and the user selects the three
operations as +, -, * then the calculation is done as follows:

3 + 9 = 12
12 - 4 = 8
8 * 1 = 8


Running the Program: 

The program begins by displaying a message to introduce the game.
A puzzle is randomly chosen and the four numbers are presented to the user. After reading 
in the operators that the user chooses, the program performs the calculation. 

Note that:
● If the user enters some number of operators other than three, an error message is displayed,
  and a new puzzle is presented.
● If the user enters an operator that is not allowed (something other than +, -, *, or /), an 
  error message is displayed, and a new puzzle is presented. 
● The number of operators entered is checked before the program checks for invalid operators. 

After performing the calculation, the program will print “Well done! You are a math genius.” 
if the result is indeed 24. Otherwise, the program will print “Sorry. Your solution did not 
evaluate to 24.” Either way, the user will then be asked if they would like to play again. When 
the program ends, the message “Thanks for playing!” is displayed.

Debug Mode:

By default, debug mode will be off. To turn it on, the user will need to use a command-line 
argument. The parameter will be as follows:
     [-d debugMode] = Whether or not to turn on debug display (1 for on / 0 for off)
If debug mode is on, then the program should find and print all solutions to the game, using 
numbers 0-9 and each mathematical operation (+, -, *, /). There are 3188 solutions.

While the real game presents numbers that have integer results each step of the way, this program 
simplifies it to allow for fractional results. This means that, for instance, 1/2*6*8 is a valid solution.
 
For the full list of solutions, see the solutions.txt file. 

Easy Mode:

By default, the program will be in easy mode. This means that the puzzle selected is randomly chosen from 
one of the following 10 puzzles:
❖ 3, 9, 4, 1
❖ 8, 5, 8, 1
❖ 6, 1, 5, 1
❖ 2, 8, 7, 8
❖ 5, 2, 9, 2
❖ 2, 6, 8, 4
❖ 5, 5, 4, 3
❖ 6, 6, 2, 6
❖ 8, 4, 2, 6
❖ 6, 2, 8, 1

Remember that the order of the numbers matters because of the way in which the calculation is performed.
To turn off easy mode, the user will need to use a command-line argument. The parameter will be as follows:
     [-e easyMode] = Whether or not easy mode should be on (1 for on / 0 for off)
If easy mode is off, then the random puzzle will be chosen from the 3188 possible solutions.