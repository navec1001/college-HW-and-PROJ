/*
    Program create a "magic box" based on user input up to a 13 x 13 "magic box"
    Written by Evan
    February, 2019
    Version 1.00
    Language: C++ (g++)
*/
//Include i/o library
#include <iostream>
//Defining the maximum array size (one more than the maximum magic box size)
#define MAXARRAY 14

//Only kinda know what this does but I do it anyways
using namespace std;

//Prototyping
void magic_maker(int m[MAXARRAY][MAXARRAY], int n);

int main(void)
{
    int magic_box[MAXARRAY][MAXARRAY] = {0}; //The Magic Box(tm)
    int user_num, //the number the user enters
        i, //row counter
        j; //column counter
    bool userGood; //whether the user's number is ok or not
    
    //initializing vars
    user_num = 0;
    
    userGood = false;

    //Telling the user what this program does
    cout<<"This program will create a magic box up to an 13 x 13 square."<<endl;

    do
    {
        //getting user input
        cout<<"Please enter an odd number less than or equal to 13"<<endl<<"> ";
        cin>>user_num;

        //user's number must be odd (mod = 1) AND less than or equal to 13 AND greater than 1
        if ((user_num % 2 == 1) && (user_num <= 13) && (user_num > 1))
            userGood = true;
    
        if (userGood == false)
            //denying bad numbers
            cout<<"The number you entered is invalid"<<endl;
    } while (userGood == false); //continue to ask for bad numbers

    //calling the function that makes the magic box
    magic_maker(magic_box, user_num);

    //nested for loops that draw the magic box
    for (i=0;i<user_num;i++)
    {
        for (j=0;j<user_num;j++)
        {
            printf(" %3d ",magic_box[i][j]);
        }
        cout<<endl;
    }  

    //terminate program
    return 0;
}

void magic_maker(int m[MAXARRAY][MAXARRAY], int n)
/*
    WHAT YOU NEED: an array "m" from main, an integer "n" from main
    Function that creates the magic box from an array passed to it and an integer passed to it
    Written by Evan
    February, 2019
    Version 1.00
    Language: C++ (g++)
*/
{
    int c, //number counter
        i,//row counter
        j,//column counter
        p,//row counter 2
        q;//column counter 2
    
    //initializing variables
    i = 0;
    j = (n/2);

    p = i;
    q = j;
    
    //putting 1 in the correct spot (top middle)
    m[i][j] = 1;

    //for loop that does all the magic
    for (c=2;c<=(n*n);c++)
    {
        //testing to see if there is another row above
        if ((p - 1) < 0)
            //if there *isn't* a row above, go to the bottom
            p = n - 1;
        else
            //if there is, go up
            p--;
        
        //testing to see if there is another column to the right
        if ((q + 1) == n)
            //if there *isn't* a row to the right, go all the way to the left
            q = 0;
        else
            //if there is, go to the right
            q++;
        
        //BIG OLD BUT: if where the next spot should be has a number,
        //OR if the next spot would be in the top right hand corner
        if ((m[p][q] != 0) || (((i--) == (-1)) && ((j++) == (n))))
        {
            //If either are true, just move down one from the original spot (j, i)
            i++;
            p = i;
            q = j;

            m[i][j] = c;
        }
        else
        {
            //if not, go to the new spot (q, p)
            i = p;
            j = q;

            m[i][j] = c;
            
        }
        
    }

    //terminate function
    return;
}