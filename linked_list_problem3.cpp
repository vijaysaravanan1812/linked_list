 using namespace std;

//reversing linked list 
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
void reverse(node *head)
{ 
    int i=1;
    node *temp = NULL;
    temp = new node();

    node *previous_node = NULL;
    previous_node = new node();
    
    node *next_node =NULL;
    next_node = new node();
    next_node = head;

    node *current_node = NULL;
    current_node = new node();
    current_node = head;

    while (next_node != NULL)
    {

        next_node = next_node ->next;
        current_node->next = previous_node;
        previous_node = current_node;
        current_node = next_node;
    }
    head = previous_node;
    temp = head;

    while (temp != NULL)
    {
        if (i == length(head))
            break;
        cout<<temp ->data<<" ";
        temp = temp ->next;
        i++;

    }
}

int main()
{
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

    cout<<"Given list is"<<"\t";
    printlist(first);cout<<"\n";

    cout<<"After reversing"<<"\t";
    reverse(first);cout<<"\n";
 
    
    return 0;
}