//creating the linked list
using namespace std;

#include<iostream>

struct node
{
    int data;
    node *next;
};

//TO print linked list
void print(node* temp)
{
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<"\n";
}

int main()
{
    node* first = NULL;
    node* second = NULL;
    node* third = NULL;

    first  = new node();
    second = new node();
    third = new node();

    cin>>first ->data;
    first->next = second;

    cin>>second ->data;
    second ->next = third;

    cin>>third ->data;  
    third ->next = NULL;

    print(first);
}