/*
    Program that takes 15 stock price inputs and outputs the stocks, the adjacent difference, the sorted stocks, the maximum, and the minimum
    Written by Evan
    April, 2019
    Version 1.00
    Language: C++ (g++)
*/
//include libraries/classes!
#include <numeric>
#include <vector>
#include <array>
#include <iostream>
#include <functional>
#include <iterator>
#include <algorithm>

//this thing again
using namespace std;

int main(void)
{
    int useless; //user input to be put into vector
    vector <int> stocks, //the vector of stock prices the user enters
                 addifstock; //vector to store adjacent difference
    //Initializing [addifstock]
    for(int i=0;i<15;i++)
        addifstock.push_back(0);

    //User intro with a bit of flare
    cout << "Hello Pickum & Loozem employee! This program will analyze a stock of your choosing over 15 days!"<<"\n\n"
    << "Please enter 15 days' worth of whole number prices for this stock:"<<endl;
    //Getting user input
    for(int i=0;i<15;i++)
    {
        cout << "Day " << i+1 << " > ";
        cin >> useless;
        stocks.push_back(useless);
        //stocks.push_back(i);
    }
    cout << "\n";

    //Repeating user's input back to them
    cout << "The stock information as you entered it is as follows: " << endl;
    for(int i=0;i<15;i++)
        cout << stocks[i] << " ";
    cout << "\n\n";

    //Calculating and displaying adjacent difference
    cout << "The difference in price per day is as follows: " << endl;
    adjacent_difference(stocks.begin(),stocks.end(),addifstock.begin());
    for(int i=0;i<15;i++)
        cout << addifstock[i] << " ";
    cout << "\n\n";
    
    //Calculating and displaying sorted stock prices
    cout << "The sorted information is as follows:" << endl;
    sort(stocks.begin(),stocks.end());
    for(int i=0;i<15;i++)
        cout << stocks[i] << " ";
    cout << "\n\n";

    //Finding and displaying max and min stock price
    cout << "The maximum price this stock achieved was " << *max_element(stocks.begin(),stocks.end()) << endl;
    cout << "The minimum price this stock achieved was " << *min_element(stocks.begin(),stocks.end()) << endl;

    return 0;
}