/*
    Program to take words from a text file and put them in two vectors based on if they start with the letter d,
    then sorting the vectors and outputting the results to the user along with the amount of times that a word appears
    Written by Evan
    Language: C++ (g++)
    Identifiers:
        inputFile, word, fileIn, dWords, otherWords, i
    Dependents:
        N/A
    Created on: 11/15/2020
    Version 1.00
*/
//including libraries to work with
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <cstdio>
#include <vector>
#include <algorithm>
//namespace std always!
using namespace std;

//custom class to hold a string and an integer
class WordInfo {
    public:
    string word; //this is the word that belongs to the class
    int wordAppears; //this is how many times the word appears in the text file

    //the constructor takes in the word to be assigned, and gives its 'wordAppears' value a default of 1
    WordInfo(string w){
        word = w;
        wordAppears = 1;
    }
};

//prototyping functions
bool compWordInfo(WordInfo a, WordInfo b);
int findWord(vector<WordInfo> v, string word);
bool wordExists(vector<WordInfo> v, string word);

int main(void){
    string inputFile; //user inputted file string
    string word; //the next word to be acted upon
    ifstream fileIn; //the usable stream for the file
    vector<WordInfo> dWords; //vector with words that start with d
    vector<WordInfo> otherWords; //vector with words that DONT start with d
    char useless; //usless char to be used at the end to halt list output

    //telling the user what the program does
    cout << "This program will output two lists: one with words that start with d" << endl <<
    "and one with words that start without d from a text file of your choosing" << endl;
    //getting user input for the file name
    cout << "Enter the file name: ";
    cin >> inputFile;

    //opening the file
    fileIn.open(inputFile.data());
    //insuring the file is open
    assert(fileIn.is_open());

    //until the end of the file is reached, do the following:
    while (!(fileIn.eof())){
        //get the next word in the file
        fileIn >> word;
        //if statement to check if there are any characters in front of the first letter, such as a quotation
        if (word[0] >= 65){
            //if statement to check if the first character is 'd'
            if (tolower(word[0]) == 'd'){
                //if it is a d word, then we work with the vector 'dWords'
                //next up is to check if the word DOES NOT exist
                if(!wordExists(dWords, word)){
                    //if the word is new, add it onto the vector
                    dWords.push_back(WordInfo(word));
                }
                else{
                    //if the word is not new, add 1 to its 'wordAppears' value
                    dWords[findWord(dWords, word)].wordAppears += 1;
                    
                }
            }
            else{
                //if it is NOT a d word, then we work with the vector 'otherWords'
                //next up is to check if the word DOES NOT exist
                if(!wordExists(otherWords, word)){
                    //if the word is new, add it onto the vector
                    otherWords.push_back(WordInfo(word));
                }
                else{
                    //if the word is not new, add 1 to its 'wordAppears' value
                    otherWords[findWord(otherWords, word)].wordAppears += 1;
                }
            }
        }
        else{
            //if statement to check if the second character is 'd'
            if (tolower(word[1]) == 'd'){
                //if it is a d word, then we work with the vector 'dWords'
                //next up is to check if the word DOES NOT exist
                if(!wordExists(dWords, word)){
                    //if the word is new, add it onto the vector
                    dWords.push_back(WordInfo(word));
                }
                else{
                    //if the word is not new, add 1 to its 'wordAppears' value
                    dWords[findWord(dWords, word)].wordAppears += 1;
                    
                }
            }
            else{
                //if it is NOT a d word, then we work with the vector 'otherWords'
                //next up is to check if the word DOES NOT exist
                if(!wordExists(otherWords, word)){
                    //if the word is new, add it onto the vector
                    otherWords.push_back(WordInfo(word));
                }
                else{
                    //if the word is not new, add 1 to its 'wordAppears' value
                    otherWords[findWord(otherWords, word)].wordAppears += 1;
                }
            }
        }
    }

    //using the std sort function along with a custom comparison function to create new, alphabetically-sorted vectors
    sort(dWords.begin(), dWords.end(), compWordInfo);
    sort(otherWords.begin(), otherWords.end(), compWordInfo);

    //to "display one screen at a time" I am asking for a simple char input to make sure the user can read the lists at their own pace
    cout << "Enter in y to see the list of d words. > ";
    cin >> useless;
    //telling the user which list is which
    cout << "List of d words:" << endl;
    //iterating through the dWords vector and displaying each word along with how many times they appear
    for(auto i = dWords.begin(); i != dWords.end(); ++i){
        cout << i->word << " appears " << i->wordAppears << " times." << endl;
    }

    //fancy dotted line to break up the lists
    cout << "----------------------------------" << endl;

    //to "display one screen at a time" I am asking for a simple char input to make sure the user can read the lists at their own pace
    cout << "Enter in y to see the list of other words. > ";
    cin >> useless;
    //telling the user which list is which
    cout << "List of other words:" << endl;
    //iterating through the otherWords vector and displaying each word along with how many times they appear
    for(auto i = otherWords.begin(); i != otherWords.end(); ++i){
        cout << i->word << " appears " << i->wordAppears << " times." << endl;
    }

    return 0;
}

/*
    Function to compare two WordInfo classes, specifically the words they contain
    Written by Evan
    Language: C++ (g++)
    Identifiers:
        a, b
    Dependents:
        N/A
    Created on: 11/15/2020
    Version 1.00
*/
bool compWordInfo(WordInfo a, WordInfo b){
    return a.word < b.word; //comparing the words' values and outputting true if the first is less than the second
}

/*
    Function to find a word contained in a vector of WordInfo objects
    Written by Evan
    Language: C++ (g++)
    Identifiers:
        v, word, counter, it
    Dependents:
        N/A
    Created on: 11/15/2020
    Version 1.00
*/
int findWord(vector<WordInfo> v, string word){
    int counter = 0; //counter to hold which position in the vector we are at currently
    vector<WordInfo>::iterator it = v.begin(); //iterator for the WordInfo vector
    //do while loop to check if the vector word matches the parameter word
    do{
        if(it->word == word){
            break; //if the words match, exit the loop
        }
        advance(it, 1); //iterators should be advanced this way if they aren't in a for loop
        counter += 1; //incrementing the counter along with the iterator
    }while (it != v.end()); //the loop will continue until the end of the vector is reached

    //returning the counter since it should be where the word is located
    return counter;
}

/*
    Function to see if a word exists in a vector of WordInfo objects
    Written by Evan
    Language: C++ (g++)
    Identifiers:
        v, word, returnBool, it
    Dependents:
        N/A
    Created on: 11/15/2020
    Version 1.00
*/
bool wordExists(vector<WordInfo> v, string word){
    //if the vector is empty, skip everything and just return false
    //if this isn't here, this program wouldn't work :)
    if (v.empty() == true) return false; 
    vector<WordInfo>::iterator it = v.begin(); //iterator for the WordInfo vector
    bool returnBool = false; //boolean variable to keep track of if the word exists or not - default value is false
    //do while loop to check if the vector word matches the parameter word
    do{
        //if the words match, change returnBool to true
        if(it->word == word){
            returnBool = true;
        }
        advance(it, 1); //iterators should be advanced this way if they aren't in a for loop
    }while (it != v.end()); //the loop will continue until the end of the vector is reached

    //returning the returnBool boolean since that keeps track of if the word exists
    return returnBool;
}