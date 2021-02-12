//2) Deleting node from linked list problem for given index
#include<iostream>

using namespace std;
struct node
{
    int data;
    node *next;
};
//To Find Length of linked list
int length(node *temp)
{
    int i=0;
    while ( temp != NULL)
    {
        temp = temp ->next;
        i++;
    }
    return i;
}

void printlist(node *temp)
{
    while (temp != NULL)
    {
        cout<<temp ->data<<" ";
        temp = temp ->next;
    }
    cout<<"\n";
}

//Function to delete node at middle of linked list
void delete_node_at_mid(node *temp,int pos)
{
    int i=1;
    node *nextnode;
    while (i < pos -1)
    {
        temp = temp ->next;
        i++;
    }
    nextnode = temp ->next;
    temp -> next = nextnode ->next;

    free(nextnode);
} 

//Function to delecting node from last
void delete_node_at_last(node *temp)
{
    node *previous_node ;
    
    while (temp ->next != NULL)
    {
        previous_node = temp;
        temp =temp ->next;
    }
    previous_node ->next = NULL;
    free(temp); 
} 

//Function to delete node at begining 
node* delete_node_at_first(node *head)
{
    node *temp = head;

    temp = head;
    head = head ->next;
    free(temp); 
    return head;
}

int main()
{

    // creating linked list
    node *first = NULL;
    node *second = NULL;
    node *third = NULL;
    node *fourth = NULL;
    node *fifth = NULL;

    first = new node();
    second = new node();
    third = new node();
    fourth = new node();
    fifth = new node();

    first ->data = 2;
    first ->next = second;

    second ->data = 4;
    second ->next = third;

    third ->data = 6;
    third ->next = fourth;

    fourth ->data = 8;
    fourth ->next = fifth;

    fifth ->data  = 10;
    fifth ->next = NULL;

    cout<<"Given linked list"<<" ";
    printlist(first);
 
    int pos;
    cout<<"Enter your position"<<" ";
    cin>>pos;
    if (pos == 1)
    {
        cout<<"First node deleted"<<" ";
        node* temp;
        temp = first;
        first = delete_node_at_first(temp);
        printlist(first);
    }
    else if (pos == length(first))
    {
        cout<<"last node deleted"<<" ";
        delete_node_at_last(first);
        printlist(first);
    }
    else if (pos > length(first))
    {
        cout<<"Invalid position"<<"\n";
    }
    
    else
    {
        cout<<"Deleting at position "<<pos<<" is deleted"<<" ";
        delete_node_at_mid(first,pos);cout<<"\n";
        printlist(first);
    }

    return 0;

}