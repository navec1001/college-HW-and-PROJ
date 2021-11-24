/*
    Program to answer three specific questions about an integer the user enters
    Written by Evan
    October, 2018
    Version 1.00
    Language: C (gcc)
*/

/*Include statements*/
#include <stdio.h> 
#include <stdbool.h>

/*Prototyping*/
void function_of_power(int f_user_number, bool *f_multiple, bool *f_sum_even, bool *f_prime);

int main(void)
{
    int     user_number; /*Number the user enters*/
    bool    multiple,   /*If this number is a multiple of 7, 11, or 13*/
            sum_even,   /*If the sum of this number's digits is even or not(odd)*/
            prime;      /*If this number is prime*/
    
    user_number = 0;
    
    /*Explaining program to user*/
    printf("This program will determine whether the number you enter is a multiple of \n");
    printf("7, 11, or 13; if the sum of the digits are even; and if the number is a prime number.\n");
    
    /*Getting user input*/
    printf("Please enter a positive integer, or -999 to exit the program > ");
    scanf("%d", &user_number);

    /*-999 is escape number*/
    while(user_number != -999)
    {
        /*Resetting question variables*/
        multiple = false;
        sum_even = false;
        prime = true;

        /*Putting in the required variables for the single function the program uses*/
        function_of_power(user_number, &multiple, &sum_even, &prime);

        /*Displaying the results of the question testing*/
        if (multiple == true) printf("%d is a multiple of 7, 11, or 13.\n", user_number);
        else printf("%d is not a multiple of 7, 11, or 13.\n", user_number);

        if (sum_even == true) printf("The sum of the digits of %d are even.\n", user_number);
        else printf("The sum of the digits of %d are odd.\n", user_number);

        if (prime == true) printf("%d is prime.\n", user_number);
        else printf("%d is not prime.\n", user_number);

    /*Repeating the process until the user enters the escape number: -999*/
    printf("Please enter another positive integer, or -999 to exit the program > ");
    scanf("%d", &user_number);
    }
}

void function_of_power(int f_user_number, bool *f_multiple, bool *f_sum_even, bool *f_prime)
/*
    Function that calculates the answers to the three specific questions of GHP#6 Details below in comments
    Written by Evan
    October, 2018
    Version 1.00
    Language: C (gcc)
*/
{
    /*Establishing function-specific variables*/
    int     i,
            num_to_sum,
            sum,
            sum_test,
            multiple_test,
            prime_test;

    /*Multiplicity Test - is this number a multiple of 7, 11, or 13?*/
    multiple_test = f_user_number % 7;
    if (multiple_test == 0) *f_multiple = true;
    else
        multiple_test = f_user_number % 11;
        if (multiple_test == 0) *f_multiple = true;
        else
            multiple_test = f_user_number % 13;
            if (multiple_test == 0) *f_multiple = true;
    
    /* Prime Test - is this number a prime number?*/
    for (i = 2; i < f_user_number; i++)
    {
        prime_test = f_user_number % i;
        if (prime_test == 0) 
        {
            *f_prime = false;
        }
    }
    /*Special case for 1 and 2, which is a prime number but the calculations wouldn't say so*/
    if (f_user_number == 1) *f_prime = true;
    if (f_user_number == 2) *f_prime = true;

    /*Sum Test - is this sum of this number's digits even?*/
    while(f_user_number != 0)
    {
        num_to_sum = f_user_number % 10;
        sum = sum + num_to_sum;
        f_user_number = f_user_number / 10;
    }
    sum_test = sum % 2;
    if (sum_test == 0) *f_sum_even = true;

    return;
}