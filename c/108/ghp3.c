/*
    Program written to compute the monthly payments of a car loan
    Written by Evan
    September, 2018
    Version 1.00
    Language: C (gcc)
*/

/*Include all the headers*/
#include <stdio.h>
#include <math.h>

/*Prototyping*/
double monthly_rate(void);
double number_of_payments(void);
void calculate_and_print(double principle, double mon_rate, double num_of_pays);
void print_results(double principle, double mon_rate, double num_of_pays, double payment);

/*MAIN*/
int main(void)
{
    double  principle,
            mon_rate,
            num_of_pays;
    
    printf ("Enter the principle amount of money borrowed (without commas): ");
    scanf ("%lf", &principle);

    mon_rate = monthly_rate();

    num_of_pays = number_of_payments();

    calculate_and_print(principle, mon_rate, num_of_pays);

    return 0;
}

/*OTHER FUNCTIONS*/
double monthly_rate(void)
{
    /*Function to get the monthly interest rate*/
    double  anl_perc,
            anl_rate,
            fmon_rate;

    printf ("Enter the annual rate of interest as a percent (without the percent symbol): ");
    scanf ("%lf", &anl_perc);
    
    //printf ("anl_perc is %f\n", anl_perc); //Commented out

    anl_rate = anl_perc / 100.0;
    //printf ("anl_rate is %f\n", anl_rate); //Commented out

    fmon_rate = anl_rate / 12.0;
    //printf ("fmon_rate is %f\n", fmon_rate); //Commented out

    return fmon_rate;
}

double number_of_payments(void)
{
    /*Function to get the number of payments the user would like to make*/
    double mon_pays;
    
    printf ("Enter the amount of payments that will be made: ");
    scanf ("%lf", &mon_pays);

    return mon_pays;
}

void calculate_and_print(double principle, double mon_rate, double num_of_pays)
{
    /*Function to calculate the monthly payment amont then print the results to the user*/
    double payment;

    payment = (mon_rate * principle) / (1 - pow(1 + mon_rate, -num_of_pays));

    print_results(principle, mon_rate, num_of_pays, payment);

    return;
}

void print_results(double principle, double mon_rate, double num_of_pays, double payment)
{
    /*Function to print all of the results of the monthly payment calculation*/
    printf ("\nPrinciple Amount:             $%8.2f\n", principle);
    printf ("Monthly Rate of Pay:           %8.2f%% \n", mon_rate * 100);
    printf ("Number of Payments:            %8.2f\n", num_of_pays);
    printf ("=}-----------------------------------------------{=\n");
    printf ("Monthly Payment:               %8.2f", payment);

    return;
}