/*
    Program to prove that global variables are garbage
    Written by Evan
    Language: C (gcc)
    Identifiers:
        N, D, Q, R, userok
    Dependents:
        N/A
    Created on: 9/7/2020
    Version 1.10 (9/8/2020)
    Taken from a GHP#1 Flowchart on CS431 Syllabus by Ron Sarner
*/
//Including library for input/output
#include <stdio.h>

//Prototyping functions
void INTDIV();

//Declaring global variables, ew
int N = 0; //Number to divide
int D = 0; //Number to divide by
int Q = 0; //Quotient of INTDIV
int R = 0; //Remainder of INTDIV

int main(void){
    
    char userok = 'y'; //Character to confirm user selections

    //Giving the user rules to follow when using the program to ensure smooth experience
    printf("***All inputs must be between 1 and 2,000,000,000***\n***Do not use commas when inputting!***\n");

    do{
    //Getting user input for global variables N and D
    printf("What number do you wish to divide?\n> ");
    scanf("%d", &N);

    printf("What are you dividing %d by?\n> ", N);
    scanf("%d", &D);

    //Ensuring the user is ok with their inputs
    printf("So you want to divide %d by %d?\nType 'y' for yes or 'n' for no:\n> ", N, D);
    scanf(" %c", &userok);
    }
    while(userok == 'n'); //if the user isn't content with their choices (n) the query will repeat to allow a second chance

    //Calling INTDIV to perform "long" integer division
    INTDIV();

    //Printing out all global variables
    printf("The value of the dividend, N, is: %d \n", N);
    printf("The value of the divisor, D, is: %d \n", D);
    printf("The value of the quotient, Q, is: %d \n", Q);
    printf("The value of the remainder, R, is: %d \n", R);

}

/*
    Function to break down integer division into its individual calculations
    Written by Evan
    Language: C (gcc)
    Identifiers:
        N, D, Q, R
    Dependents:
        N/A
    Created on: 9/7/2020
    Version 1.00 (9/7/2020)
    Taken from a GHP#1 Flowchart on CS431 Syllabus by Ron Sarner
*/
void INTDIV(){
    Q = 0; //setting the quotient equal to 0
    while (N >= D){ //while the dividend is larger than the divisor, perform int division... otherwise the dividend is the remainder/not divisible
        N=N-D; //subtract the divisor from the dividend
        Q=Q+1; //add one to the quotient
    }
    R=N; //the remainder becomes whatever is left of the dividend
    return;
}