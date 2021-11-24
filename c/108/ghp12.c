/*
    Program to store employee information via a linked list
    Written by Evan; Some parts taken from Ron/Classwork (Will be indicated)
    November, 2018
    Version 1.00
    Language: C (gcc)
*/

/*Include libraries*/
#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 

/*Employee struct/linked list*/
typedef struct employee
{
    char first_name[15];
    char last_name[15];
    int id;
    struct employee *next;
} EMPL;

/*Prototyping*/
EMPL* add_employee(EMPL *no_touch);
void display_high_id(EMPL *no_touch);


int main(void)
{
    /*Pointers to the head of the linked list and the one that runs down the list*/
    EMPL *head,
         *run;
    /*Number of employees and counter*/
    int employee_count,
        i;
    
    /*Starting with head pointing to nothing*/
    head = NULL;

    /*Getting how many employees the user is going to enter in*/
    printf("How many employees do you have? > ");
    scanf("%d", &employee_count);

    /*For loop that will add each employee until the user entered amount is reached*/
    /*Comes from Ron/Classwork*/
    for(i=0; i<employee_count;i++)
        head = add_employee(head);
    
    /*Func to display the employee with the highest ID*/
    display_high_id(head);

    /*Terminate program*/
    return 0;
}

EMPL* add_employee(EMPL *no_touch)
/*
    Function to add employee information to the linked list
    Written by Evan; Some parts taken from Ron/Classwork (Will be indicated)
    November, 2018
    Version 1.00
    Language: C (gcc)
*/
{
    /*Pointers to current struct and the runner pointer*/
    EMPL *cur,
         *run;
    /*First Name, Last Name and ID variables that will be put into the structs*/
    char fname[15],
         lname[15];
    int iden;

    /*Initialize iden*/
    iden = 0;

    /*Get employee information from user*/
    printf("What is this employee's first name? > ");
    scanf("%s", fname);
    printf("What is this employee's last name? > ");
    scanf("%s", lname);
    printf("What is this employee's id? > ");
    scanf("%d", &iden);

    /*Making employee struct and giving it user information...*/
    /*Comes from Ron/Classwork*/
    cur = (EMPL*)malloc(sizeof(EMPL));
    strcpy(cur->first_name, fname);
    strcpy(cur->last_name, lname);
    cur->id = iden;
    cur->next = NULL;

    /*...then adding the struct to a linked list*/
    /*Comes from Ron/Classwork*/
    if (no_touch == NULL)
        no_touch = cur;
    else
    {
        run = no_touch;
        while (run->next!=NULL)
            run = run->next;
        run->next = cur;
    }

    /*Returning the pointer to the head of the linked list*/
    return(no_touch);
}

void display_high_id(EMPL *no_touch)
/*
    Function to display the employee with the highest ID from the linked list
    Written by Evan; Some parts taken from Ron/Classwork (Will be indicated)
    November, 2018
    Version 1.00
    Language: C (gcc)
*/
{
    /*Pointers for the runner and the highest ID employee*/
    EMPL *run,
         *high_employee;
    /*Value of the highest ID*/
    int high_id;
    
    /*initializing pointers and variables*/
    run = no_touch;
    high_employee = NULL;
    high_id = run->id;

    /*running down the linked list*/
    /*Adapted from Ron/Classwork*/
    while(run->next!=NULL)
    {
        run = run->next;

        /*testing for highest ID employee*/
        if(high_id < run->id)
        {
            high_employee = run;
            high_id = run->id;
        }
    }

    /*Displaying the information of the employee with the highest ID*/
    printf("Here is the information of the employee with the highest id:\n");
    printf("First Name:     %s\n", high_employee->first_name);
    printf("Last Name:      %s\n", high_employee->last_name);
    printf("ID:             %d\n", high_employee->id);

    return;
}