/*
    Program to hash words into a vector of strings and the user may search for words
    Written by Evan
        Class syntax taken from ghp4's given stack class
    May, 2019
    Version 1.00
    Language: C++ (g++)
*/
//including everything!
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cctype>
#include <cstring>
#include <cstdio>
//this for the last time!
using namespace std;
//default capacity of the vector
#define DEFAULT_CAP 23

//global var, i know, but it's for all the counting in the vector class (and i guess beyond)
int v = 0;

//the almighty hashh class (because hash is taken already)
class Hashh
{
 public:
    //default constructor
    Hashh()
    {
        for(v=0;v<hashh_capacity;v++)
            vhashh.push_back("0");  
    }
    //constructor if you wanted to change the cap
    Hashh(const int & cap)
    {
        hashh_capacity = cap;
        for(v=0;v<hashh_capacity;v++)
            vhashh.push_back("0");   
    }   
    //class function to store a word into the hashh vector
    void store(const string & storeMe)
    {
        int hashed = 0,
            first = 0,
            last = 0;
        bool insert = false;
        
        first = storeMe[0];
        last = storeMe[storeMe.size()-1];
        hashed = ((first) +  (last))%23;

        v=hashed;

        while (insert == false)
        {
            if (vhashh[v] == "0")
            {
                vhashh[v] = storeMe;
                insert = true;
            }
            else
            {
                if (v==(hashh_capacity-1))
                {
                    v = 0;
                }
                else
                {
                    v++;
                }
            }
        }
    }
    //class function to display the hashh vector entirely
    void display(ostream & out) const
    {
        for(v=0;v<hashh_capacity;v++)
            cout << v << ": " << vhashh[v] << endl;
    }
    //class function to search for an inputted word
    void search(const string & searchMe)
    {
        int hashed = 0,
            first = 0,
            last = 0;
        bool found = false;
        string foundMe;

        first = searchMe[0];
        last = searchMe[searchMe.size()-1];
        hashed = ((first) +  (last))%23;

        v=hashed;

        while (found == false)
        {
            if (vhashh[v] == "0")
            {
                if (v==(hashh_capacity-1))
                {
                    v = 0;
                }
                else
                {
                    v++;
                    if (v == hashed)
                    {
                        found = true;
                        cout << "The word " << searchMe << " was not found." << endl;
                    }
                }
            }
            else
            {
                if (vhashh[v] == searchMe)
                {
                    foundMe = vhashh[v];
                    found = true;
                    cout << "The word " << foundMe << " was found in position " << v << "." << endl;
                }
                else
                {
                    if (v==(hashh_capacity-1))
                    {
                        v = 0;
                    }
                    else
                    {
                        v++;
                        if (v == hashed)
                        {
                            found = true;
                            cout << "The word " << searchMe << " was not found." << endl;
                        }
                    }  
                }
            }
            
        }
    }

 private:
    vector <string> vhashh; //the almighty vector itself
    int hashh_capacity = DEFAULT_CAP; //the cap of said vector
};



int main(void)
{
    Hashh ghp; //the incarnation of the almighty class hashh
    string userInput, //the user's inputted word to be stored
           userSearch, //the user's inputted word to be searched
           userStop; //the user's input if they want to stop searching for words
    bool stop = false; //bool on if we should stop

    //intro to the user
    cout << "Welcome to Hayward's Hash Diner where all we have is hash" << endl
    << "Please enter 15 words:" << endl;
    //getting 15 user inputted words to be stored
    for (int i = 0;i<15;i++)
    {
        cout << "> ";
        cin >> userInput;
        ghp.store(userInput);
    }
    ghp.display(cout); //displaying the vector after the user inputs all of their words
    //constantly asking the user to search for a word and asking if they want to keep going
    while (stop == false)
    {
        cout << "Please enter a word to be searched for:" << endl
        << "> ";
        cin >> userSearch;
        ghp.search(userSearch);
        cout << "Would you like to search for another word?" <<endl
        << "y/n > ";
        cin >> userStop;
        if (userStop == "N" || userStop == "n")
            stop = true;
    }
    return 0;
}