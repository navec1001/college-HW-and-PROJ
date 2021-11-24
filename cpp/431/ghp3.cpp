/*
    Program to recursively make concentric squares out of a use-inputted word
    Written by Evan
    Language: C++ (g++)
    Identifiers:
        myWord.word, myWord.wordSize, myWord.wordArray
    Dependents:
        N/A
    Created on: 10/21/2020
    Version 1.00
*/
//Including iostream for i/o purposes and string to be able to work with strings
#include <iostream>
#include <string>
//namespace standard, of course
using namespace std;

//making a class to hold a word string, the size of said string, and an array of characters that will be making up the concentric squares
class GhpWord {
    //all data will be public for the purposes of this GHP, I am full aware private is superior
    public:
        string word;
        int wordSize;
        char wordArray [9];
};

//Prototyping my recursive function
void concentricSquares(GhpWord funcWord, int env);

int main(void){
    //making an instance of my class, GhpWord
    GhpWord myWord; 
    //getting the user-inputted word to make concentric squares out of, and storing it in the object
    cout << "Please a word made up of 5 or less letters:" << endl;
    cin >> myWord.word;
    //getting the size of the string and storing it in the object for future use
    myWord.wordSize = myWord.word.size();
    //error checker, because the array in the class cannot go beyond 9 chars the word cannot be longer than 5 characters - otherwise the program is aborted
    if (myWord.wordSize > 5)
    {
        cout << "Invalid word length! Reboot the program and try a shorter word!" << endl;
        return 0;
    }
    //spitting user-inputted information back at the user
    cout << "The word you entered is " << myWord.word << " and it is " << myWord.wordSize << " characters long." << endl;
    cout << "I will now construct " << myWord.wordSize << " concentric squares using the characters in this word, hold tight..." << endl;
    //starting recursion
    concentricSquares(myWord, 1);
    //recursive function will handle the rest of the program, once the recursion has stopped the program is finished
    return 0;
}

/*
    Function to recursively make concentric squares out of a word passed by value via a class
    Written by Evan
    Language: C++ (g++)
    Identifiers:
        funcWord, env, charPos, addChar, arraySize,startPos, i, j, k
    Dependents:
        N/A
    Created on: 10/21/2020
    Version 1.00
*/
void concentricSquares(GhpWord funcWord, int env){
    //charPos is for the array position of the character in the word that will be overwriting other characters on the array
    int charPos = funcWord.wordSize - env; //it is calculated by taking the word size and subtracting the environment number

    //addChar is the character that will be overwriting other characters on the array
    char addChar = funcWord.word[charPos]; //it is calculated by taking charPos and using that to determine which part of the word a character will be saved from

    //arraySize is the size of the array of characters
    int arraySize = funcWord.wordSize + (funcWord.wordSize - 1); //it is calculated by taking the word size + one less than the word size

    //startPos is the starting position of the character that overwrites others on the big array
    int startPos = -1 + env; //it is calculated by adding -1 to the env

    //this for loop overwrites characters on the wordArray with the addChar, starting at startPos and ending at a point determined by taking away the environment number from the arraySize
    //this fills in the character while leaving other characters on the edges of the array
    for(int i = -1 + env; i <= arraySize - env; i++)
    {
        funcWord.wordArray[i] = addChar;
    }
    
    //next, wordArray is outputted
    for (int j = 0; j < arraySize; j++)
        cout << funcWord.wordArray[j];
    cout << endl;

    //if the character position is 0, then half of the squares are created and its time to unwind the recursion, printing the other half of the squares
    if (charPos == 0)
    {
        return;
    }
    else //when the character position is not 0, the squares are not done and more layers must be created, so recursion is continued
    {
        concentricSquares(funcWord, env + 1);
    }
    
    //wordArray is outputted again, making the other half of the squares
    for (int k = 0; k < arraySize; k++)
        cout << funcWord.wordArray[k];
    cout << endl;

    //finally, the recursive function ends
    return;
}