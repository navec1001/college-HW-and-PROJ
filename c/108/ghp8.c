/*
    Program to test the validity of a UPC Code
    Written by Evan
    November, 2018
    Version 1.00
    Language: C (gcc)
*/
#include <stdio.h> 

int main(void)
{
    int upc[13],
        i,
        oddsum,
        evensum,
        totalsum,
        first_digit,
        checkdigit;
    
    /*0th spot is a nothing spot because I don't want to deal with that*/
    upc[0] = 0;

    /*Telling the user what's up*/
    printf("This program checks the validity of a UPC code.\n");

    /*Getting the UPC Code*/
    for(i=1;i<13;i++)
    {
        printf("Digit %d > ", i);
        scanf(" %d", &upc[i]);
    }

    /*Odd numbered cell sum*/
    for(i=1;i<=11;i=i+2)
    {
        oddsum = oddsum + upc[i];
    }

    /*Multiply that bad boy by 3*/
    oddsum = oddsum * 3;

    /*Even numbered cell sum*/
    for(i=2;i<=10;i=i+2)
    {
        evensum = evensum + upc[i];
    }

    /*Get the total of odd and even*/
    totalsum = oddsum + evensum;

    /*Snatch the first digit*/
    first_digit = totalsum % 10;

    /*If the first digit is 0 leave it be that's the check digit, but if not 
    subtract it from 10 and then that's the check digit*/
    if(first_digit == 0)
    {
        checkdigit = first_digit;
        printf("The check digit is 0\n");
    }
    else
    {
        checkdigit = 10 - first_digit;
        printf("The check digit is %d\n", checkdigit);
    }

    /*Finally, seeing if the check digit and last digit match up and displaying the results*/
    if(checkdigit == upc[12])
    {
        printf("The UPC Code is valid\n");
    }
    else
    {
        printf("The UPC Code is invalid\n");
    }

    /*And scene*/
    return 0;
}