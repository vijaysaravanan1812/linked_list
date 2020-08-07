//pair wish swap the linked list
using namespace std;

#include<iostream>

struct node
{
    int data;
    node *next;
};
void printlist(node *temp)
{
    while (temp != NULL)
    {
        cout<<temp ->data<<" ";
        temp = temp ->next;

    }
    cout<<"\n";
}



void pair_wise_swap(node *head)
{
    node *temp = NULL;int temp1;
    temp = new node();
    temp = head;
    while (temp ->next != NULL && temp != NULL)
    {
        temp1 = temp ->data;
        temp ->data = temp ->next ->data;
        temp ->next ->data = temp1;
        temp = temp ->next ->next;
    }
    

}




int main()
{
    node *first = NULL;
    node *second = NULL;
    node *third =NULL;
    node *fourth = NULL;
    node *fifth =NULL;

    first = new node();
    second = new node();
    third = new node();
    fourth = new node();
    fifth = new node();

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
    pair_wise_swap(first);
    printlist(first);

    return 0;


  
}