/*
    Program to open an input file of words, and print and count palindromes
    Written by Evan
    April, 2019
    Version 1.00
    Language: C++ (g++)
*/
//include libraries/classes!
#include <iostream>
#include <stack>
#include <queue>
#include <fstream>
#include <string>
#include <cassert>

//Still here
using namespace std;

int main(void)
{
    string rawInputFile, //user inputted file
           word; //a word in the file
    string::iterator iw; //an iterator for the word string
    ifstream inputFile; //the input file that has been opened/processed
    stack <char> reverse; //the stack, which will read the word in reverse
    queue <char> forward; //the queue, which will read the word regularly
    int palCount = 0, //a count of palindromes in the file
        length = 0, //length of the word
        palCheck = 0, //the checker for amount of letters that match
        wordCount = 0; //the amount of words in the file

    //telling the user what the program does
    cout<<"This program will take your input file (one word per line)and point out the palindromes"<<endl<<endl
    <<"Please enter an input file"<<endl<<"> ";
    //getting user input
    cin >> rawInputFile;

    //opening the file and assuring it is open
    inputFile.open(rawInputFile.data());
    assert(inputFile.is_open());

    //while the file is not done...
    while (!(inputFile.eof()))
    {
        //getting a word from the file to process
        inputFile>>word;
        //setting the string iterator to the beginning of the word
        iw = word.begin();

        //using the iterator to read each character into the stack and the queue at once
        while(iw < word.end())
        {
            reverse.push(tolower(*iw));
            forward.push(tolower(*iw));
            iw++;
        }
        
        //getting the length of the word
        length = reverse.size();

        //popping characters from the stack and the queue and comparing them
        while(!(reverse.empty()) && !(forward.empty()))
        {
            if(reverse.top()==forward.front())
                palCheck++;
            
            reverse.pop();
            forward.pop();            
        }

        //if all the letters match, print the word and add 1 to the palindrome count
        if(length==palCheck)
        {
            palCount++;
            cout << word << endl;
        }

        //at the end of the word processing, add one to the word count and reset [palCheck]
        wordCount++;
        palCheck = 0;
    }

    //print out how many palindromes there were out of all the words
    cout << "Out of " << wordCount << " words, " << palCount << " were palindromes!" << endl;

    //terminate program
    return 0;
}