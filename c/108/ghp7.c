/*
    Program to demonstrate representational error with nested for loops
    Written by Evan
    October, 2018
    Version 1.00
    Language: C (gcc)
*/

#include <stdio.h>

int main(void)
{
    /*Establishing counting variables and sum variable*/
    int i,
        j;
    double  sum;

    /*First for loops that keeps track of the denominator and how many times the fractions will be added together*/
    for(i=2;i<=30;i++)
    {
        /*Resetting sum variable each iteration*/
        sum = 0.0;

        /*Second for loop that will iterate the amount of times each specific fraction needs to be added to itself*/
        for(j=1;j<=i;j++)
        {
            sum = sum + 1.0/i;
        }

        /*Testing which sums are over 1, equal to 1, or under 1*/
        if(sum > 1.0) 
        {
            printf("Adding 1/%d %d times is greater than 1\n", i, i);
        }
        else if(sum == 1.0) 
        {
            printf("Adding 1/%d %d times is equal to 1\n", i, i);
        }
        else
        {
            printf("Adding 1/%d %d times is less than 1\n", i, i);
        }
    }
}