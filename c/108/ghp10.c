/*
    Program to take an input from the user and output a number after going through a specific recursive function
    Written by Evan
    November, 2018
    Version 1.00
    Language: C (gcc)
*/
/*Including things*/
#include <stdio.h> 

/*Prototyping*/
int calc(int x);

int main(void)
{
    int input,      /*The input that the user will enter*/
        output;     /*The output after going through the recursive function*/
    
    /*Getting user input*/
    printf("Input an integer: ");
    scanf("%d", &input);

    /*Calculating the output via a recursive function*/
    output = calc(input);

    /*Displaying the output for the user*/
    printf("The result is: %d", output);

    /*Terminate program*/
    return 0;
}

int calc(int x)
/*
    Recursive function that puts the user inputted variable 'input' through multiple recursive calculations
    Written by Evan
    October, 2018
    Version 1.00
    Language: C (gcc)
*/
{
    /*End of the recursion, if x hits 0 or is less than*/
    if (x <= 0)
        return x + 3;
    /*The recursive aspect, when x is greater than 0*/
    else
        return calc(x-3) + (x+5);
}