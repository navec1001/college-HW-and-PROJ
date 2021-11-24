/*
    Program to calculate the average of a user-determined amount of items that the user also enters in
    Written by Evan
    October, 2018
    Version 1.00
    Language: C (gcc)
*/
#include <stdio.h> 

int get_total_values(void);
double add_sum(int total_values);
double calc_average(double sum, int total_values);

int main(void)
{
    /*Establishing main variables*/
    int total_values;
    double  avg,
            sum;

    /*Explaining what this program does to the user*/
    printf("This program will average an amount of values that you will determine and enter.\n");
    printf("An example of a use: finding the average grade of an assignment in a class.\n");

    /*Retreiving how many values in total there will be from user*/
    total_values = get_total_values();

    /*Summing up all of the values that the user enters in*/
    sum = add_sum(total_values);
    
    /*Calculating the average of the values the user has entered*/
    avg = calc_average(sum, total_values);

    /*Displaying results of the program to the user*/
    printf("With %d values ", total_values);
    printf("the average of the values you have entered is: %6.2f.", avg);

    return 0;
}

int get_total_values(void)
/*
    Function to retrieve the user's input for how many items total there will be
    Written by Evan
    October, 2018
    Version 1.00
    Language: C (gcc)
*/
{
    int total_values;

    printf("Enter the number of values you are averaging> ");
    scanf("%d", &total_values);

    return total_values;
}

double add_sum(int total_values)
/*
    Function to retrieve each value and adding them into one sum variable
    Written by Evan
    October, 2018
    Version 1.00
    Language: C (gcc)
*/
{
    int i;
    double  sum,
            number;
    
    for(i = 0; i < total_values; i++)
    {
            printf("Enter a value> ");
            scanf("%lf", &number);

            sum = sum + number;
    }

    return sum;
}

double calc_average(double sum, int total_values)
/*
    Function to calculate the average of the sum of the items and the total values the user entered
    Written by Evan
    October, 2018
    Version 1.00
    Language: C (gcc)
*/
{
    double average;

    average = sum / total_values;

    return average;
}