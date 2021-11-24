/*
    Program find the prime factorization of a number greater than 1
    Written by Evan
        Uses Nyhoff's Stack Class
    March, 2019
    Version 1.00
    Language: C++ (g++)
*/
//including i/o library and header file for Stack Class
#include <iostream>
using namespace std;
#include "stack.h"

//Prototyping
void S_prime_factor(int num, Stack* primefac);

int main(void)
{
    int num; //user inputted number we will find the prime factorization of
    Stack primefac; //Stack we will be storing the prime factorization of num in

    num = 0; //initializing num

    //informing the user
    cout << "This is a program that will determine the prime factorization-\n-of a number and display it in a stack format" << endl;
    cout << "Please enter a whole number greater than 1" << endl;
    //getting user input
    cin >> num;
    //calling S_prime_factor, which will find the prime factorization of "num", and store it in Stack "primefac"
    S_prime_factor(num, &primefac);
    //displaying the prime factorization of num
    cout << "The prime factorization of " << num << " is:" << endl;
    primefac.display(cout);

    //terminate program
    return 0;
}

void S_prime_factor(int num, Stack* primefac)
/*
    Function that finds the prime factorization of a given number and stores it in a Stack
    Preconditions: 
        integer "num" - the number that we will find the prime factorization of
        Stack "primefac" - the Stack that we will be storing the prime factorization in
    Postconditions:
        Stack "primefac" - will contain the prime factorization of "num"
        return - nothing, this is a void function
    Written by Evan
    March, 2019
    Version 1.00
    Language: C++ (g++)
*/
{
    int i; //counter int
    i = 2; //initializing i
    //while loop that will continute until the num reaches 1 (where the prime factorization process ends)
    while(num != 1)
    {
        //if the number divides evenly into num, then it is a factor
        if ((num % i) == 0)
        {
            primefac->push(i); //add factor to prime factorization Stack
            num = num / i; //actually divide the number
            i = 2; //set i back to 2 to start the process over again
        }
        //if the number doesn't divide evenly into num, then it isn't a factor
        else
            i++; //add 1 to i
    }

    //return from the function
    return;
}