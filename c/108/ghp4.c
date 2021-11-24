/*
    Program to calculate user BMI and categorize them
    Written by Evan
    October, 2018
    Version 1.00
    Language: C (gcc)
*/

/*Including necessary headers */
#include <stdio.h>
#include <math.h>

/*Prototyping functions */
double get_height(void);
double get_weight(void);
double calc_bmi(double height, double weight);
void bmi_print_and_category(double bmi);

int main(void)
/*
    Main Function
    Written by Evan
    October, 2018
    Version 1.00
    Language: C (gcc)
*/
{
    /*Establishing variables */
    double  height,
            weight,
            bmi;
    
    /*Introducing the program */
    printf ("This program will take your height in inches (ins.) and weight in pounds (lbs.),\n");
    printf ("calculate your Body Mass Index (BMI),\n");
    printf ("then categorize you based on your BMI\n");
    printf ("--------------------------------------\n");

    /*Getting user inputs for height and weight */
    height = get_height();
    weight = get_weight();

    printf ("--------------------------------------\n");

    /*Calculating the BMI based on user inputted height and weight */
    bmi = calc_bmi(height, weight);

    /*Print out the user's BMI and print out their categorization */
    bmi_print_and_category(bmi);

    return 0;
}

double get_height(void)
/*
    Function to get user input for the height variable
    Written by Evan
    October, 2018
    Version 1.00
    Language: C (gcc)
*/
{
    double height;

    printf ("Enter your height in inches (ins.): ");
    scanf ("%lf", &height);

    return height;
}

double get_weight(void)
/*
    Function to get user input for the weight variable
    Written by Evan
    October, 2018
    Version 1.00
    Language: C (gcc)
*/
{
    double weight;

    printf ("Enter your weight in pounds (lbs.): ");
    scanf ("%lf", &weight);

    return weight;
}

double calc_bmi(double height, double weight)
/*
    Function to calculate BMI based on user input for height and weight variables
    Written by Evan
    October, 2018
    Version 1.00
    Language: C (gcc)
*/
{
    double bmi;
    bmi = (703 * weight) / (pow(height, 2.0));

    return bmi;
}

void bmi_print_and_category(double bmi)
/*
    Function to output BMI categorization based on calculated BMI
    Written by Evan
    October, 2018
    Version 1.00
    Language: C (gcc)
*/
{
    printf ("Your Body Mass Index (BMI) is %5.2f\n", bmi);

    if (bmi < 18.5) printf ("That means you are underweight");
    else
        if (bmi < 25.0) printf ("That means you are a normal weight");
        else
            if (bmi < 30.0) printf ("That means you are overweight");
            else
                printf ("That means you are obese");
}