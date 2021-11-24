/*
    Program to output how many of a text file's words DO NOT start with d/D
    Adapted from Ron's cs240s19-2/14 classwork by Evan
    February, 2019
    Version 1.00
    Language: C++ (g++)
*/
//include libraries/classes!
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <cstdio>

//this thing again
using namespace std;

int main(void)
{
    int no_d; //how many words don't start with d/D
    string inputFile; //the input file from the user
    string word; //the word in the file (one by one)
    ifstream fileIn; //the input file but I can actually use it

    //Letting the user know what's up
    cout<<"This program will determine how many words in a file do not start with the letter 'd' (regardless of case)."<<endl;
    //Getting the user's file
    cout<<"Enter the file name: ";
    cin>>inputFile;

    //Opening said file
    fileIn.open(inputFile.data());
    //MAKING SURE IT'S OPEN
    assert(fileIn.is_open());

    //as long as the open file isn't at the end...
    while (!(fileIn.eof()))
    {
    //take whatever (string) is in the open file and put it into word (a string)
    fileIn>>word;
    //if the first letter of the word isn't d/D (it lowercases it)
    if (tolower(word[0]) != 'd')
        no_d++; //add 1 to the no_d counter
    }

    //Telling the user how many words don't start with d/D
    cout<<no_d<<" words do not start with d or D";

    //Terminating program (>.>)
    return 0;
}