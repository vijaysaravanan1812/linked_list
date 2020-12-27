//linked list problem 
//1) inserting elements and use local declaration
using namespace std;

#include<iostream>
int s;
struct node
{
    int data;
    node *next;
};

//To Find Length of linked list
int length(node *temp)
{
    int i=1;
    while ( temp != NULL)
    {
        temp = temp ->next;
        i++;
    }
    return i;
}

//To Print the linked list
void printlist(node *temp)
{
    while ( temp != NULL)
    {
        cout<<temp ->data<<" ";
        temp = temp ->next; // temp = second,third,NUll
    }
    cout<<"\n";
}

//This function is to insert the element at last in linked list
void insert_end(node *temp)
{
    node *nextnode;
    nextnode = new node();
    cout<<"your new element"<<"\t"; 
    cin>>nextnode -> data;
    nextnode ->next = NULL;
    while ( temp ->next != NULL)
    {
        temp = temp ->next;
    }
    temp ->next =  nextnode ;
}

//This function to insert element at first
node* insert_first(node* temp )
{
    node *newnode = NULL;
    newnode = new node();

    cout<<"Your new element"<<"\t";
    cin>>newnode ->data;
    newnode ->next = NULL;
    newnode ->next = temp;
    temp = newnode;
    return temp;
    
}

//This function is to insert element at any position
void insert(node *temp ,int position)
{
    int count=1;
    node *newnode;  
    newnode = new node();
    cout<<"your new element"<<"\t"; 
    cin>>newnode -> data;
     
    while (count != position - 1)
    {

        temp = temp ->next;
        count++;
    } 
    newnode->next = temp ->next;
    temp ->next = newnode;
}


int main()
{
    int position;
    
   printf("Enter the element for creating linked list\n");
    node *first = (struct node *) malloc(sizeof(struct node));
    node *second =  (struct node *)malloc(sizeof(struct node));
    node *third =   (struct node *)malloc(sizeof(struct node));
    node *fourth = (struct node *) malloc(sizeof(struct node));
    node *fifth =  (struct node *) malloc(sizeof(struct node));
    
    cin>>first ->data;
    first ->next =second;

    cin>>second ->data;
    second ->next = third;  

    cin>>third ->data;
    third ->next = fourth; 

    cin>>fourth ->data;
    fourth ->next = fifth; 

    cin>>fifth ->data;
    fifth ->next = NULL; 

    printlist(first);
    cout<<"Enter the position\t";
    cin>>position;
 
    
    if (position == 1)
    {
        node* temp;temp = new node();
        temp = first;
        first = insert_first(temp);
        printlist(first);
    }
    else
    {
        if (position > length(first))
        {
            cout<<"Invalid position"<<"\n";
        }
        if (position == (length(first) + 1))
        {
            insert_end(first);
            printlist(first);
        }   
        if (position <= length(first))
        {
            insert(first,position);
            printlist(first);
        }
    }
    return 0;
}