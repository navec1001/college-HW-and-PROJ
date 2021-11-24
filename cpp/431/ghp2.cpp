/*
    Program to prove that global variables are garbage via an array sorting algorithm
    Written by Evan
    Language: C++ (g++)
    Identifiers:
        n, a[10], j, temp, k, sw
    Dependents:
        N/A
    Created on: 9/21/2020
    Version 1.10 (10/4/2020)
    Taken from a GHP#2 Flowchart on CS431 Syllabus by Ron Sarner
*/
//including library for input/output
#include <iostream>
//using the standard namespace
using namespace std;

//first global identifiers:
int n; //for number of spaces to be taken in the array...
int a [11]; //the array of integers that will be sorted

//prototyping functions
void sort();
void move();
void Findkay();

int main(void){

    //first, get the user input for how many of the 10 available spaces on the array they want to take up
    cout << "Enter how many numbers that will be in the array that will be sorted (Min = 1, Max = 10)" << endl << "Numbers in Array = ";
    cin >> n;

    if(n > 10 || n < 1){
        cout << "That is not a valid number! Please restart the program and try again!" << endl;
        return 0;
    }

    //next, get the user inputs for the individual numbers in the array
    for(int i = 1; i <= n; i++){
        cout << "What number will be in slot " << i << "? > ";
        cin >> a[i];
    }

    //execute the sorting function
    sort();

    //print out the new, sorted array for the user
    for(int i = 1; i <= n; i++){
        cout << "The new number in slot " << i << " is " << a[i] << endl;
    }

    //terminate program
    return 0;

}

//declaring another global variable to be used in sort, move, and Findkay... it is unnecessary in main so it was defined here for ease of use
int j;

/*
    Function to sort a global array
    Written by Evan
    Language: C++ (g++)
    Identifiers:
        n, a[10], j
    Dependents:
        N/A
    Created on: 9/21/2020
    Version 1.00 (9/21/2020)
    Taken from a GHP#2 Flowchart on CS431 Syllabus by Ron Sarner
*/
void sort (){
    
    //letting the ser know that sorting has begun, makes the output easier to read too!
    cout << "Sorting now..." << endl;
    //for loop that tests if the next spot in the array is less than the current, and if so... move em around!
    for(j = 1; j <= n-1; j++){
        if(a[j] > a[j+1]){
            move();
        }
    }

    return;
}

//declaring another global variable to be used in move and Findkay... it is unnecessary in main and sort so it was defined here for ease of use
int temp, k;

/*
    Function to move two integers around in an array
    Written by Evan
    Language: C++ (g++)
    Identifiers:
        n, a[10], j, temp, k
    Dependents:
        N/A
    Created on: 9/21/2020
    Version 1.00 (9/21/2020)
    Taken from a GHP#2 Flowchart on CS431 Syllabus by Ron Sarner
*/
void move(){

    //letting temp hold the lesser integer
    temp = a[j+1];
    //putting the greater integer
    a[j+1] = a[j];

    //executing Findkay to find 'k', which should be temp's (the less integer) proper place in the array
    Findkay();

    //put the lesser integer in its proper place
    a[k] = temp;

    return;
}

//declaring another global variable to be used in Findkay... it is unnecessary in main, sort, and move so it was defined here for ease of use
int sw;

/*
    Function to find an integer's proper place in a sorted array
    Written by Evan
    Language: C++ (g++)
    Identifiers:
        n, a[10], j, temp, k, sw
    Dependents:
        N/A
    Created on: 9/21/2020
    Version 1.00 (9/21/2020)
    Taken from a GHP#2 Flowchart on CS431 Syllabus by Ron Sarner
*/
void Findkay(){

    //setting k as the current place in the array
    k = j;
    //setting the detector variable as 0 so the while loop works
    sw = 0;

    while(k > 1 && sw == 0){ //as long as k is greater than one (spot in the array, has to be greater than 1 (for the purposes of this program)) AND the detector variable is 0
        if(a[k-1] > temp){ //if the previous integer in the array is greater than the temp integer, move the value and counter down
            a[k] = a[k-1];
            k = k-1;
        }
        else{
            sw = 1; //if the proper place is found, the detector variable is set to 1 which will deactivate the while loop
        }
    }
    
    return;
}