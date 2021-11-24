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
    int jclass; //an integer to keep track of which class a job is
    //0 = Class A
    //1 = Class B
    //2 = Class C
    struct node *next; //a pointer to the next struct, required for a linked struct
};

//defining global pointers
struct node* front = NULL; //front of the A Queue
struct node* back = NULL; //back of the A Queue
struct node* temp = NULL; //a pointer used for temporary movements
struct node* a_part = NULL; //what is considered the "A Class Partition"
struct node* b_part = NULL; //what is considered the "B Class Partition"
struct node* c_part = NULL; //what is considered the "C Class Partition"

//Prototyping functions
void Insert (int value, int jclass); //function to insert nodes into Queue A
void Pop(); //function to remove a node from Queue A
void Display(); //function to display all nodes in Queue A

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
   0 <= random <= 49: Add a job to the Job Queue
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
            cout<<"A job has entered the system...";

            if (0 <= random && random <=25)
            {
                cout<<"...as a Class A job"<<endl;
                Insert(iteration, 0);
            }
            else if (26 <= random && random <= 39)
            {
                cout<<"...as a Class B job"<<endl;
                Insert(iteration, 1);
            }
            else if (40 <= random && random <= 49)
            {
                cout<<"...as a Class C job"<<endl;
                Insert(iteration, 2);
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
            if (front != NULL)
            {
                if (front->jclass == 2 || front->jclass == 1 || front->jclass == 0)
                {
                    c_part = front;
                    Pop();
                }
            }
            else
                c_part = NULL;
        }

        //Partition B is smaller than C, but larger than A and can process Class A or B jobs
        if (b_part == NULL)
        {
            if (front != NULL)
            {
                if (front->jclass == 1 || front->jclass == 0)
                {
                    b_part = front;
                    Pop();
                }
            }
            else
                b_part = NULL;
        }

        //Partition A is the smallest and can only process Class A jobs
        if (a_part == NULL)
        {
            if (front != NULL)
            {
                if (front->jclass == 0)
                {
                    a_part = front;
                    Pop();
                }
            }
            else
                a_part = NULL;
        }

        //EVERY 5 ITERATIONS -> DISPLAY SIMULATION INFORMATION
        if (iteration % 5 == 0)
        {
            cout<<"The current state of each queue is as follows: "<<endl;
            Display();

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

//the following three functions define how to insert a node struct into the job queue
void Insert(int value, int newclass)
{
    if (back == NULL)
    {
        back = (struct node *)malloc(sizeof(struct node));
        back->id = value;
        back->jclass = newclass;
        back->next = NULL;
        front = back;
    }
    else
    {
        temp = (struct node *)malloc(sizeof(struct node));
        back->next = temp;
        temp->id = value;
        temp->jclass = newclass;
        temp->next = NULL;
        back = temp;
    }
}

//the following function defines how to pop a node struct out of the job queue
void Pop() 
{
   temp = front;
   if (front == NULL) 
   {
        cout<<"Job Queue is empty"<<endl;
        return;
   }
   else if (temp->next != NULL) 
   {
        temp = temp->next;
        cout<<front->id<<" was popped from Job Queue"<<endl;
        front = temp;
   } 
   else 
   {
        cout<<front->id<<" was popped from Job Queue"<<endl;
        front = NULL;
        back = NULL;
   }
}

//the following function defines how to display the job queue
void Display() 
{
   temp = front;

   if ((front == NULL) && (back == NULL)) 
   {
      cout<<"Job Queue is empty!"<<endl;
      return;
   }

   cout<<"Job Queue: ";

   while (temp != NULL) 
   {
      cout<<temp->id<<" ";
      temp = temp->next;
   }

   cout<<endl;
}