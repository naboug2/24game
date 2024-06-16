/*------------------------------------------- 
The 24 Game 
System: VS Code on MacOS
Author: Nuha Abougoash
------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

// the following function runs through all the possible combinations where 4 random numbers can equal to 24
void all_solutions(double hard_array[3188][4], char op_array[3188][3], bool pAll) { //will take in 4 random numbers and if a 
    char operator[4] = {'+', '-', '*', '/'}; // declare and intitialize the 4 operators
    int count = 0;
    double ab, abc, abcd;
    
    /// the first 4 for loops , i,j,k,l loop through the numbers 1-9
    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            for (int k = 1; k < 10; k++) {
                for (int l = 1; l < 10; l++) {

                    // after looping through each number, we loop through all possible operators 3 times (once for every input)
                    // we are assigning ab to the rhand value and looping thru all numbers and op to get a sum
                    for (int m = 0; m < 4; m++) {    
                        //ab = i operator[m] j                    
                        if ( operator[m] == '+') {
                            ab = (double)i  +  (double)j;   
                        }
                        else if ( operator[m] == '-') {
                            ab = (double)i  -  (double)j;   
                        }
                        else if ( operator[m] == '*') {
                            ab = (double)i  *  (double)j;   
                        }
                        else if ( operator[m] == '/') {
                            ab = (double)i  /  (double)j;   
                        }
                        
                        // this loop is going thru all numbers and op and summing them with the ab value                         
                        for (int n = 0; n < 4; n++) {
                            //abc = ab operator[n]  k
                            if ( operator[n] == '+') {
                                abc = ab  +  (double)k;   
                            }
                            else if ( operator[n] == '-') {
                                abc = ab  -  (double)k;   
                            }
                            else if ( operator[n] == '*') {
                                abc = ab  *  (double)k;   
                            }
                            else if ( operator[n] == '/') {
                                abc = ab  /  (double)k;   
                            }

                            // this loop is going thru all numbers and op and summing them with the abc value
                            for (int s = 0; s < 4; s++) {
                                //abcd = abc operator[s] l
                                if ( operator[s] == '+') {
                                    abcd = abc  +  (double)l;   
                                }
                                else if ( operator[s] == '-') {
                                    abcd = abc  -  (double)l;   
                                }
                                else if ( operator[s] == '*') {
                                    abcd = abc  *  (double)l;   
                                }
                                else if ( operator[s] == '/') {
                                    abcd = abc  /  (double)l;   
                                }

                                // abcd return the sum after all four numbers are calculated and summed based off the each operator
                                if (fabs(abcd - 24) < 0.001) { 
                                    hard_array[count][0] = i; //this grabs a,b,c & d
                                    hard_array[count][1] = j;
                                    hard_array[count][2] = k;
                                    hard_array[count][3] = l;
                                    op_array[count][0] = operator[m]; //this grabs the proper operator
                                    op_array[count][1] = operator[n];
                                    op_array[count][2] = operator[s];

                                    count++; // counts all 3188 solutions

                                    // this checks if debug is on, then print all the solutions
                                    if (pAll == true) { printf("%d. %d%c%d%c%d%c%d\n", count, i, operator[m], j, operator[n], k, operator[s], l); }
                                    
                                }
                            }
                        }    
                    }
                }
            }
        }
    }
}

// The following function plays the game using only the easy puzzles
void run_easy(int easy_array[4]) {

    bool game_over = false; 
    // begin a while loop to run the game
    while (!game_over) {
        // declare and initialize the array for all 10 given puzzles
        int easy_puzzles[10][4]= {{3,9,4,1}, {8,5,8,1}, {6,1,5,1}, {2,8,7,8}, {5,2,9,2}, {2,6,8,4}, {5,5,4,3}, {6,6,2,6}, {8,4,2,6}, {6,2,8,1}};
        int random = (rand() % 10); //randomly choose one of the 10 puzzles
        int sum, sum2, sum3;
        char input[10]; 

        printf("The numbers to use are: ");
        // the following for loop prints the number the user will play
        for(int i = 0; i < 4; i++) {

            easy_array[i] = easy_puzzles[random][i]; 

            if(i != 3) {
                printf("%d, ", easy_array[i]); // print out the first 3 numbers
            }
            else {
                printf("%d.\n", easy_array[i]);  // end with this final number
            }
        }
        
        printf("Enter the three operators to be used, in order (+,-,*, or /): ");
        scanf("%s" , input); // takes users input
        int op_num = strlen(input); // checks the lenght of input string

        // the following if statements check for any errors in the user input
        if ( ( op_num > 3) || ( op_num < 3)) { // prints error if lenght is less than or greater than 3 operators
            printf("Error! The number of operators is incorrect. Please try again.\n");
            continue;
        }
        // prints error if any of the input are not +,-,*, or /
        if ( (input[0] != '+') && (input[0] != '-') && (input[0] != '/') && (input[0] != '*'))  {
            printf("Error! Invalid operator entered. Please try again.\n");
            printf("\n");
            continue;
        }
        if ( (input[1] != '+') && (input[1] != '-') && (input[1] != '/') && (input[1] != '*')) {
            printf("Error! Invalid operator entered. Please try again.\n");
            printf("\n");
            continue;
        }
        if ( (input[2] != '+') && (input[2] != '-') && (input[2] != '/') && (input[2] != '*')) {
            printf("Error! Invalid operator entered. Please try again.\n");
            printf("\n");
            continue;
        }

        // the following if-else statements calculate the sum properly by computing the calculations based on the corresponding operator
        if (input[0] == '+') {
            sum = easy_array[0] + easy_array[1];
            printf("%d + %d = %d.\n", easy_array[0], easy_array[1], sum);
        }
        else if (input[0] == '-') {
            sum = easy_array[0] - easy_array[1];
            printf("%d - %d = %d.\n", easy_array[0], easy_array[1], sum);
        }
        else if (input[0] == '*') {
            sum = easy_array[0] *  easy_array[1];
            printf("%d * %d = %d.\n", easy_array[0], easy_array[1], sum);
        }
        else if (input[0] == '/') {
            sum = easy_array[0] / easy_array[1];
            printf("%d / %d = %d.\n", easy_array[0], easy_array[1], sum);
        }

        sum2 = sum; 
        // setting sum2 = sum, will allow us to add onto the previous sum and compute the next calculation based on the corresponding operator
        if (input[1] == '+') {
            sum += easy_array[2];
            printf("%d + %d = %d. \n", sum2, easy_array[2], sum);
        }
        else if (input[1] == '-') {
            sum -= easy_array[2];
            printf("%d - %d = %d. \n", sum2, easy_array[2], sum);
        }
        else if (input[1] == '*') {
            sum *= easy_array[2];
            printf("%d * %d = %d. \n", sum2, easy_array[2], sum);
        }
        else if (input[1] == '/') {
            sum /= easy_array[2];
            printf("%d / %d = %d. \n", sum2, easy_array[2], sum);
        }

        // setting sum3 = sum, will allow us to add onto the previous sum and compute the next calculation based on the corresponding operator
        sum3 = sum;
        if (input[2] == '+') {
            sum += easy_array[3];
            printf("%d + %d = %d.\n", sum3, easy_array[3], sum);
        }
        else if (input[2] == '-') {
            sum -= easy_array[3];
            printf("%d - %d = %d.\n", sum3, easy_array[3], sum);
        }
        else if (input[2] == '*') {
            sum *= easy_array[3];
            printf("%d * %d = %d.\n", sum3, easy_array[3], sum);
        }
        else if (input[2] == '/') {
            sum /= easy_array[3];
            printf("%d / %d = %d.\n", sum3, easy_array[3], sum);
        }

        // now we have the sum after it is computed using the users 3 inputed operators
        if (sum == 24) {
            printf("Well done! You are a math genius.\n");
            printf("\n");
        }
        else {
            printf("Sorry. Your solution did not evaluate to 24.\n");
            printf("\n");
        }

        // ask user if they would like to continue playing
        printf("Would you like to play again? Enter N for no and any other character for yes.\n");
        scanf("%s" ,input);
        if (input[0] == 'N') {
            printf("Thanks for playing!");
            game_over = true; // set game_over = true to end the game if user enters 'N' 
        }
        else {
            continue; // otherwise run the game again
        }
    }
}

// The following function plays the game using only the hard puzzles
void run_hard(double all_solutions[3188][4]) {
    double hard_array[4]; // this will hold the value of the users 4 random numbers
    
    bool game_over = false;
    // begin a while loop to run the game 
    while (!game_over) {
        int random = (rand() % 3188); //randomly choose one of the 3188 puzzles
        int sum, sum2, sum3;
        char input[10]; 

        printf("The numbers to use are: ");
        // the following for loop prints the number the user will play
        for(int i = 0; i < 4; i++) {
            hard_array[i] = all_solutions[random][i];

            if (i != 3) {
                printf("%d, ", (int)hard_array[i]); // print out the first 3 numbers
            }
            else {
                printf("%d.\n", (int)hard_array[i]);
            }
        }
        
        printf("Enter the three operators to be used, in order (+,-,*, or /): ");
        scanf("%s" , input); // takes users input
        int op_num = strlen(input); // checks the lenght of input string

        // the following if statements check for any errors in the user input
        if ( ( op_num > 3) || ( op_num < 3)) {
            printf("Error! The number of operators is incorrect. Please try again.\n");
            continue;
        }

        // prints error if any of the input are not +,-,*, or /
        if ( (input[0] != '+') && (input[0] != '-') && (input[0] != '/') && (input[0] != '*'))  {
            printf("Error! Invalid operator entered. Please try again.\n");
            printf("\n");
            continue;
        }
        if ( (input[1] != '+') && (input[1] != '-') && (input[1] != '/') && (input[1] != '*')) {
            printf("Error! Invalid operator entered. Please try again.\n");
            printf("\n");
            continue;
        }
        if ( (input[2] != '+') && (input[2] != '-') && (input[2] != '/') && (input[2] != '*')) {
            printf("Error! Invalid operator entered. Please try again.\n");
            printf("\n");
            continue;
        }

        // the following if-else statements calculate the sum properly by computing the calculations based on the corresponding operator
        if (input[0] == '+') {
            sum = hard_array[0] + hard_array[1];
            printf("%d + %d = %d.\n", (int)hard_array[0], (int)hard_array[1], (int)sum);
        }
        else if (input[0] == '-') {
            sum = hard_array[0] - hard_array[1];
            printf("%d - %d = %d.\n", (int)hard_array[0], (int)hard_array[1], (int)sum);
        }
        else if (input[0] == '*') {
            sum = hard_array[0] *  hard_array[1];
            printf("%d * %d = %d.\n", (int)hard_array[0],(int)hard_array[1], (int)sum);
        }
        else if (input[0] == '/') {
            sum = hard_array[0] / hard_array[1];
            printf("%d / %d = %d.\n", (int)hard_array[0], (int)hard_array[1], (int)sum);
        }

        sum2 = sum;
        // setting sum2 = sum, will allow us to add onto the previous sum and compute the next calculation based on the corresponding operator
        if (input[1] == '+') {
            sum += hard_array[2];
            printf("%d + %d = %d. \n", (int)sum2, (int)hard_array[2], (int)sum);
        }
        else if (input[1] == '-') {
            sum -= hard_array[2];
            printf("%d - %d = %d. \n", (int)sum2, (int)hard_array[2], (int)sum);
        }
        else if (input[1] == '*') {
            sum *= hard_array[2];
            printf("%d * %d = %d. \n", (int)sum2, (int)hard_array[2], (int)sum);
        }
        else if (input[1] == '/') {
            sum /= hard_array[2];
            printf("%d / %d = %d. \n", (int)sum2, (int)hard_array[2], (int)sum);
        }
       
        // setting sum3 = sum, will allow us to add onto the previous sum and compute the next calculation based on the corresponding operator
        sum3 = sum;
        if (input[2] == '+') {
            sum += hard_array[3];
            printf("%d + %d = %d.\n", (int)sum3, (int)hard_array[3], (int)sum);
        }
        else if (input[2] == '-') {
            sum -= hard_array[3];
            printf("%d - %d = %d.\n", (int)sum3, (int)hard_array[3], (int)sum);
        }
        else if (input[2] == '*') {
            sum *= hard_array[3];
            printf("%d * %d = %d.\n", (int)sum3, (int)hard_array[3], (int)sum);
        }
        else if (input[2] == '/') {
            sum /= hard_array[3];
            printf("%d / %d = %d.\n", (int)sum3, (int)hard_array[3], (int)sum);
        }

        // now we have the sum after it is computed using the users 3 inputed operators
        if (sum == 24) {
            printf("Well done! You are a math genius.\n");
            printf("\n");
        }
        else {
            printf("Sorry. Your solution did not evaluate to 24.\n");
            printf("\n");
        }

        // ask user if they would like to continue playing
        printf("Would you like to play again? Enter N for no and any other character for yes.\n");
        scanf("%s" , input);
        if (input[0] == 'N') {
            printf("Thanks for playing!");
            game_over = true; // set game_over = true to end the game if user enters 'N' 
        }
        else {

            continue; // otherwise run the game again
        }
    }
}

// the main function takes in command line args as its parameters
int main(int argc, char *argv[]) {
    int easy = 1; //default easy on
    int debug = 0; //default debug off
    int easy_array[4];
    double hard_array[3188][4];
    char op_array[3188][3];
    bool pAll;

    // diplay the introduction
    printf("Welcome to the game of TwentyFour.\n");
    printf("Use each of the four numbers shown below exactly once, \n");
    printf("combining them somehow with the basic mathematical operators (+,-,*,/) \n");
    printf("to yield the value twenty-four. \n");
    printf("\n");

    srand(1);

    // the following for loop reads the command line arguments
    for (int i = 1; i < argc; i++) { // loop through the number of string in cl
        if (argv[i][1] == 'e') {  // if e, then easy mode
            easy = atoi(argv[++i]);
        } 
        else if (argv[i][1] == 'd') { //if d, then debug mode
            debug = atoi(argv[++i]); 
        } 
    }

    if (easy == 1 && debug == 1 ) { // debug on & easy on 
        pAll = true; //print all solutions
        all_solutions(hard_array, op_array, pAll);  // run all solutions
        run_easy(easy_array); // run the easy puzzles
    }
    if (easy == 1 && debug == 0) { // easy on & debug off   
        //do not print all solutions
        run_easy(easy_array);  // run the easy puzzles 
    }
    if (easy == 0 && debug == 0 ) { //easy off & debug, off     
        pAll = false; // do not print all solutions
        all_solutions(hard_array, op_array, pAll); // run all solutions
        run_hard(hard_array);   //run hard puzzles
        
    }
    if ( easy == 0 && debug == 1) {  //easy off & debug on 
        pAll = true; // print all solutions
        all_solutions(hard_array, op_array, pAll);  // run all solutions
        run_hard(hard_array); //run hard puzzles
    }

    return 0;
}
