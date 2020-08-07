//2) Deleting node from linked list problem 
using namespace std;

#include<iostream>
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
    node *nextnode = NULL;
    nextnode = new node();
    while (i < pos -1)
    {
        temp = temp ->next;
        i++;
    }
    nextnode = temp ->next;
    temp -> next =nextnode ->next;

    free(nextnode);
} 

//Function to delecting node from last
void delete_node_at_last(node *temp)
{
    node *previous_node =NULL;
    previous_node = new node();
    
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
    node *temp = NULL;
    temp = new node();

    temp = head;
    head = head ->next;
    free(temp); 
    return head;
}

int main()
{
    int pos;
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

    cin>>first ->data;
    first ->next = second;

    cin>>second ->data;
    second ->next = third;

    cin>>third ->data;
    third ->next = fourth;

    cin>>fourth ->data;
    fourth ->next = fifth;

    cin>>fifth -> data;
    fifth ->next = NULL;

    cout<<"Given linked list"<<" ";
    printlist(first);
 
    cout<<"Enter your position";
    cin>>pos;
    if (pos == 1)
    {
        cout<<"First node deleted"<<" ";
        node* temp = NULL;
        temp = new node();

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