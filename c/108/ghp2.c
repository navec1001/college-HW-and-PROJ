/*
	Program to convert degrees Farenheit to degrees Celsius
	Written by Evan Carioggia
	September 2018
	Version 1.0
	Language: C (gcc target)
*/

#include <stdio.h>

int main (void)
{
	/*Establishing variables*/
	double 	fa, //farenheit input
		 	ce; //celsius output
	
	/*Getting user Farenheit input*/
	printf ("Enter degrees Fahrenheit \n> "); 
	scanf ("%lf", &fa); 
	
	/*Calculation into degrees Celsius*/
	ce = (fa-32)*5.0/9.0; 
	
	/*Outputting degrees Farenheit and degrees Celsius*/
	printf ("Degrees Farenheit:	%8.2f \n", fa); 
	printf ("Degrees Celsius:	%8.2f", ce);
	
	/*Terminating the program*/
	return(0); 
}
