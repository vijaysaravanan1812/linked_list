//Detect the loop in linked list 
//Floyd's cycle
using namespace std;
#include<iostream>

struct node
{
    int data;
    node *next;
};

int detectloop(node *head)
{
    node *fast = NULL,*slow = NULL;
    slow = new node();
    fast = new node();
    slow = head;fast = head;
    while (slow && fast && fast->next )
    {
        slow = slow->next;
        fast = fast ->next ->next;
        if (slow == fast)
        {
            return 1;
        }
    }
    return -1;
}

int main()
{
    node *first = NULL;
    node *second =  NULL;
    node *third = NULL;
    node *fourth =NULL;
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
    fourth ->next =fifth;

    cin>>fifth ->data;
    fifth -> next = second;

    if (detectloop(first) == 1)
    {
        cout<<"Given liked list has loop"<<"\n";
    }
    else
    {
        cout<<"Given linked list has no loop"<<"\n";
    }
    
    

    return 0;
}