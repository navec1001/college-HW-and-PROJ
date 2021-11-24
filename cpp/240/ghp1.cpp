/*
    Program to search for a user inputted number in a premade 2D array
    Written by Evan
    January, 2019
    Version 1.00
    Language: C++ (g++)
*/

//including i/o lib
#include <iostream>

//idk what this means yet
using namespace std;

//this will be the 2D array size: 2x2
#define ARRAYSIZE 2

//Prototypes
int LS(int l[ARRAYSIZE][ARRAYSIZE], int it);

//main
int main(void)
{
    int array[ARRAYSIZE][ARRAYSIZE] = //the premade array
            {
                {1, 2},
                {3, 4}
            },
        user_search, //the user's input
        result; //whether the user input is in the array
    
    //initialize variables
    user_search = 0;
    result = 0;
    
    //outputting what this program does for users
    cout<<"This program will take a value you input and output whether it is in a premade array."<<endl;
    //getting user input
    cout<<"Input a number to search for: ";
    cin>>user_search;

    //call function that tests for user input in array
    result = LS(array, user_search);

    //displaying to the user that their number...
    if (result == 1)
        cout<<user_search<<" is in the array."; //is in the array
    if (result == 0)
        cout<<user_search<<" is not in the array.";//isn't in the array
    
    //terminate program
    return 0;
}

int LS(int l[ARRAYSIZE][ARRAYSIZE], int it)
/*
    Function to search for a user inputted number (passed by input) in a premade 2D array (also passed, but by reference)
    Written by Evan
    January, 2019
    Version 1.00
    Language: C++ (g++)
*/
{
    //establishing local variables
    int inarray, //whether or not the passed number is in the array
        i, //row counter
        j; //column counter

    //initializing inarray
    inarray = 0;
    
    //nested for loop which is the actual chunk that tests for each cell to see if it is equal to user input (it)
    for (i=0;i<2;i++)
    {
        for (j=0;j<2;j++)
        {
            if (l[i][j] == it)
                inarray = 1; //1 is true
        }
    }

    //returns result (0 for false, 1 for true)
    return inarray;
}