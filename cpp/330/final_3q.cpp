//including proper libraries
#include <iostream>
#include <cstdlib>
#include <ctime>

//namespace standard is, ironically, the standard for this program
using namespace std;

//defining node structure within any linked list made
struct node 
{
    int id; //an id integer to keep better track of which job is where
    struct node *next; //a pointer to the next struct, required for a linked struct
};

//defining global pointers
struct node* a_front = NULL; //front of the A Queue
struct node* a_back = NULL; //back of the A Queue
struct node* b_front = NULL; //front of the B Queue
struct node* b_back = NULL; //back of the B Queue
struct node* c_front = NULL; //front of the C Queue
struct node* c_back = NULL; //back of the C Queue
struct node* temp = NULL; //a pointer used for temporary movements
struct node* a_part = NULL; //what is considered the "A Class Partition"
struct node* b_part = NULL; //what is considered the "B Class Partition"
struct node* c_part = NULL; //what is considered the "C Class Partition"

//Prototyping functions
void Insert_A(int value); //function to insert nodes into Queue A
void Insert_B(int value); //function to insert nodes into Queue B
void Insert_C(int value); //function to insert nodes into Queue C
void Pop_A(); //function to remove a node from Queue A
void Pop_B(); //function to remove a node from Queue B
void Pop_C(); //function to remove a node from Queue C
void Display_A(); //function to display all nodes in Queue A
void Display_B(); //function to display all nodes in Queue B
void Display_C(); //function to display all nodes in Queue C

int main(void)
{

    int iteration = 1; //var to keep track of iteration number, also used for job identification
    int random = 0; //the random number to be generated each iteration
    int a_jobs = 0; //number of A Class jobs executed
    int b_jobs = 0; //number of B Class jobs executed
    int c_jobs = 0; //numbre of C Class jobs executed
    /*generating a random seed via srand and using time as the variable, since it has the most
    randomization potential*/
    srand(time(NULL));
    //srand(0);
   
   /*the massive for loop that generates a random number and decides what to do with said number
   0 <= random <= 25: Add a job to the A Queue
   26 <= random <= 39: Add a job to the B Queue
   40 <= random <= 50: Add a job to the C Queue
   50 <= random <= 75: Finish execution of the job waiting in Partiton A (if any)
   76 <= random <= 89: Finish execution of the job waiting in Partition B (if any)
   90 <= random <= 100: Finish execution of the job waiting in Partition C (if any)
   */
    for (iteration = 1;iteration <= 100;iteration++)
    {
        //GENERATE RANDOM NUMBER
        random = rand() % 101;

        //0->50: JOB ENTERED THE SYSTEM
        if (0 <= random && random <= 49)
        {
            cout<<"A job has entered the system..";

            //0->25: JOB ENTERED A QUEUE
            if (0 <= random && random <= 25)
            {
                cout<<"..that is Class A"<<endl;

                Insert_A(iteration);
            }
            //26->39: JOB ENTERED B QUEUE
            else if (26 <= random && random <= 39)
            {
                cout<<"..that is Class B"<<endl;

                Insert_B(iteration);
            }
            //40->50: JOB ENTERED C QUEUE
            else if (40 <= random && random <= 49)
            {
                cout<<"..that is Class C"<<endl;

                Insert_C(iteration);
            }
            else
            {
                cout<<"Error, thought to be 0 through 49 but wasn't"<<endl;
            }
        }
        //51->100: PARTITION HAS COMPLETED A JOB
        else if (50 <= random && random <= 100)
        {
            cout<<"A job has finished execution..";

            //50->75: PARTITION A HAS COMPLETED A JOB (IF ANY)
            if (50 <= random && random <= 75)
            {
                if (a_part !=NULL)
                {
                    cout<<"..in Partition A"<<endl;
                    free(a_part);
                    a_part = NULL;
                    a_jobs += 1;
                }
                else
                {
                    cout<<"..but Partition A is empty"<<endl;
                }
            }
            //76->89: PARTITION B HAS COMPLETED A JOB (IF ANY)
            else if (76 <= random && random <= 89)
            {
                if (b_part !=NULL)
                {
                    cout<<"..in Partition B"<<endl;
                    free(b_part);
                    b_part = NULL;
                    b_jobs += 1;
                }
                else
                {
                    cout<<"..but Partition B is empty"<<endl;
                }
            }
            //90->100: PARTITION C HAS COMPLETED A JOB (IF ANY)
            else if (90 <= random && random <= 100)
            {
                if (c_part !=NULL)
                {
                    cout<<"..in Partition C"<<endl;
                    free(c_part);
                    c_part = NULL;
                    c_jobs += 1;
                }
                else
                {
                    cout<<"..but Partition C is empty"<<endl;
                }
            }
            else
            {
                cout<<"Error, thought to be 50 through 100 but wasn't"<<endl;
            }
        }
        else
        {
            cout<<"Error, random number wasn't in between 0 and 100"<<endl;
        }

        //MOVE JOBS IN QUEUES TO A PARTITION THAT HAS THE CAPACITY TO PROCESS THEM
        //Partition C is the largest and can process Class A, B, or C jobs
        if (c_part == NULL)
        {
            if (c_front != NULL)
            {
                c_part = c_front;
                Pop_C();
            }
            else if (b_front != NULL)
            {
                c_part = b_front;
                Pop_B();
            }
            else if (a_front != NULL)
            {
                c_part = a_front;
                Pop_A();
            }
            else
                c_part = NULL;
        }

        //Partition B is smaller than C, but larger than A and can process Class A or B jobs
        if (b_part == NULL)
        {
            if (b_front != NULL)
            {
                b_part = b_front;
                Pop_B();
            }
            else if (a_front != NULL)
            {
                b_part = a_front;
                Pop_A();
            }
            else
                b_part = NULL;
        }

        //Partition A is the smallest and can only process Class A jobs
        if (a_part == NULL)
        {
            if (a_front != NULL)
            {
                a_part = a_front;
                Pop_A();
            }
            else
                a_part = NULL;
        }

        //EVERY 5 ITERATIONS -> DISPLAY SIMULATION INFORMATION
        if (iteration % 5 == 0)
        {
            cout<<"The current state of each queue is as follows: "<<endl;
            Display_A();
            Display_B();
            Display_C();

            cout<<"The current state of each partition is as follows: "<<endl;
            if (a_part == NULL)
                cout<<"Partition A is empty!"<<endl;
            else
                cout<<"Partition A: job id "<<a_part->id<<endl;
            if (b_part == NULL)
                cout<<"Partition B is empty!"<<endl;
            else
                cout<<"Partition B: job id "<<b_part->id<<endl;
            if (c_part == NULL)
                cout<<"Partition C is empty!"<<endl;
            else
                cout<<"Partition C: job id "<<c_part->id<<endl;
            
            cout<<a_jobs<<" jobs of Class A have been executed."<<endl;
            cout<<b_jobs<<" jobs of Class B have been executed."<<endl;
            cout<<c_jobs<<" jobs of Class C have been executed."<<endl;
        }
    }
    

    return 0;
}

/*the following three functions define how to insert a node struct into one of the 
three linked lists for the three queues required*/
void Insert_A(int value)
{
    if (a_back == NULL)
    {
        a_back = (struct node *)malloc(sizeof(struct node));
        a_back->id = value;
        a_back->next = NULL;
        a_front = a_back;
    }
    else
    {
        temp = (struct node *)malloc(sizeof(struct node));
        a_back->next = temp;
        temp->id = value;
        temp->next = NULL;
        a_back = temp;
    }
}

void Insert_B(int value)
{
if (b_back == NULL)
    {
        b_back = (struct node *)malloc(sizeof(struct node));
        b_back->id = value;
        b_back->next = NULL;
        b_front = b_back;
    }
    else
    {
        temp = (struct node *)malloc(sizeof(struct node));
        b_back->next = temp;
        temp->id = value;
        temp->next = NULL;
        b_back = temp;
    }
}

void Insert_C(int value)
{
if (c_back == NULL)
    {
        c_back = (struct node *)malloc(sizeof(struct node));
        c_back->id = value;
        c_back->next = NULL;
        c_front = c_back;
    }
    else
    {
        temp = (struct node *)malloc(sizeof(struct node));
        c_back->next = temp;
        temp->id = value;
        temp->next = NULL;
        c_back = temp;
    }
}

/*the following three functions define how to pop a node struct out of one of the 
three linked lists for the three queues required*/
void Pop_A() 
{
   temp = a_front;
   if (a_front == NULL) 
   {
        cout<<"A is empty"<<endl;
        return;
   }
   else if (temp->next != NULL) 
   {
        temp = temp->next;
        cout<<a_front->id<<" was popped from A"<<endl;
        //free(a_front);
        a_front = temp;
   } 
   else 
   {
        cout<<a_front->id<<" was popped from A"<<endl;
        //free(a_front);
        a_front = NULL;
        a_back = NULL;
   }
}

void Pop_B() 
{
   temp = b_front;

   if (b_front == NULL) 
   {
        cout<<"B is empty"<<endl;
        return;
   }

   else if (temp->next != NULL) 
   {
        temp = temp->next;
        cout<<b_front->id<<" was popped from B"<<endl;
        //free(b_front);
        b_front = temp;
   }

   else 
   {
        cout<<b_front->id<<" was popped from B"<<endl;
        //free(b_front);
        b_front = NULL;
        b_back = NULL;
   }
}

void Pop_C() 
{
   temp = c_front;

   if (c_front == NULL) 
   {
        cout<<"C is empty"<<endl;
        return;
   }

   else if (temp->next != NULL) 
   {
        temp = temp->next;
        cout<<c_front->id<<" was popped from C"<<endl;
        //free(c_front);
        c_front = temp;
   } 

   else 
   {
        cout<<c_front->id<<" was popped from C"<<endl;
        //free(c_front);
        c_front = NULL;
        c_back = NULL;
   }
}

/*the following three functions define how to display one of the 
three linked lists for the three queues required*/
void Display_A() 
{
   temp = a_front;

   if ((a_front == NULL) && (a_back == NULL)) 
   {
      cout<<"A is empty!"<<endl;
      return;
   }

   cout<<"Queue A: ";

   while (temp != NULL) 
   {
      cout<<temp->id<<" ";
      temp = temp->next;
   }

   cout<<endl;
}

void Display_B() 
{
   temp = b_front;

   if ((b_front == NULL) && (b_back == NULL)) 
   {
      cout<<"B is empty!"<<endl;
      return;
   }

   cout<<"Queue B: ";

   while (temp != NULL) 
   {
      cout<<temp->id<<" ";
      temp = temp->next;
   }

   cout<<endl;
}

void Display_C() 
{
   temp = c_front;

   if ((c_front == NULL) && (c_back == NULL)) 
   {
      cout<<"C is empty!"<<endl;
      return;
   }

   cout<<"Queue C: ";

   while (temp != NULL) 
   {
      cout<<temp->id<<" ";
      temp = temp->next;
   }

   cout<<endl;
}