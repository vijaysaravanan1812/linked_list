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
    node *nextnode = new node();
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
    node *newnode = new node();
    cout<<"Your new element"<<"\t";
    cin>>newnode ->data;
    newnode ->next = temp;
    temp = newnode;
    return temp;
}

//This function is to insert element at any position
void insert(node *temp ,int position)
{
    node *newnode = new node();
    cout<<"your new element"<<"\t"; 
    cin>>newnode -> data;

    int count = 1;     
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
    
    node *first = (struct node *) malloc(sizeof(struct node));
    node *second =  (struct node *)malloc(sizeof(struct node));
    node *third =   (struct node *)malloc(sizeof(struct node));
    node *fourth = (struct node *) malloc(sizeof(struct node));
    node *fifth =  (struct node *) malloc(sizeof(struct node));
    
    first ->data = 2;
    first ->next =second;

    second ->data = 4;
    second ->next = third;  

    third ->data = 6;
    third ->next = fourth; 

    fourth ->data = 8;
    fourth ->next = fifth; 

    fifth ->data = 10;
    fifth ->next = NULL; 

    printf("Given linked list\n");
    printlist(first);

    int position;
    cout<<"Enter the position\t ";
    cin>>position;
 
    
    if (position == 1)
    {
        node* temp = first;
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