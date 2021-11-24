/*
    Program that accesses a struct to store book information
    Written by Evan
    November, 2018
    Version 1.00
    Language: C (gcc)
*/

/*Including appropriate libraries*/
#include <stdio.h> 
#include <string.h>

/*Struct: Book; stores information about a book the user inputs*/
struct Book
    {
        char title[30];
        char author[30];
        char genre[20];
        int id;
    };

int main(void)
{
    struct Book user_book; /*Book user is to input information about*/

    /*Telling the user what's up*/
    printf("This program will save information you enter on a book\n");
    
    /*Getting the book's title from the user*/
    printf("Please enter the book's title: ");
    gets(user_book.title);

    /*Getting the book's author's name from the user*/
    printf("Please enter the book's author: ");
    gets(user_book.author);

    /*Getting the book's genre from the user*/
    printf("Please enter the book's genre: ");
    gets(user_book.genre);

    /*Getting the book's ID number from the user*/
    printf("Please enter the book's id number: ");
    scanf("%d", &user_book.id);

    /*Printing back the book's information to the user*/
    printf("The information on the book is as follows: \n");
    printf("Title:\t %s\n", user_book.title);
    printf("Author:\t %s\n", user_book.author);
    printf("Genre:\t %s\n", user_book.genre);
    printf("ID:\t %d\n", user_book.id);

    /*Terminate program*/
    return 0;
}