/*
    Program to pluralize words entered by the user
    Written by Evan
    November, 2018
    Version 1.00
    Language: C (gcc)
*/
#include <stdio.h> 
#include <string.h> 

#define MAX 15

int main(void)
{
    char    noun[MAX];      /*The noun itself*/
    int     pos_end,        /*The last character of the noun*/
            pos_twoend;     /*The second to last character of the noun */
    int     len;            /*The length of the noun*/
    
    /*Telling the user what's up & getting input*/
    printf("This program will show you the plural form of a noun of your choice.\n");
    printf("Enter a noun > ");
    gets(noun);

    printf("The noun you entered is %s\n", noun);

    /*Setting lengths for last character and second to last character*/
    len = strlen(noun);
    pos_end = len-1;
    pos_twoend = len-2;

    /*Testing for y at the end*/
    if(noun[pos_end] == 'y')
    {
        noun[pos_end] = '\0';
        strcat(noun, "ies");
    }
    /*Testing for s, sh, and ch at the end*/
    else if(noun[pos_end] == 's')
        strcat(noun, "es");
    else if((noun[pos_twoend] == 's') && (noun[pos_end] == 'h'))
        strcat(noun, "es");
    else if((noun[pos_twoend] == 'c') && (noun[pos_end] == 'h'))
        strcat(noun, "es");
    /*If not y, s, sh, or ch, then just slap on s at the end*/
    else
        strcat(noun, "s");

    /*Displaying plural results*/
    printf("and its plural form is %s", noun);

    /*Terminate program*/
    return 0;
}