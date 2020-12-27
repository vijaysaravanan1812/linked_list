// 3) reversing linked list 
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
node* reverse(node *head)
{ 
    node* previous_node = NULL;
    previous_node = new node();

    node* current_node = NULL;
    current_node = new node();

    node* next_node =   NULL;
    next_node = new node();

    current_node = head;
    next_node = head;
    while (next_node != NULL)
    {
        next_node = next_node ->next;
        current_node ->next = previous_node;
        previous_node = current_node;
        current_node = next_node;
    }
    head = previous_node;
    printlist(head);
    return head;

}

int main()
{
    node *first = NULL, *temp = NULL;
    node *second = NULL;
    node *third = NULL;
    node *fourth = NULL;
    node *fifth = NULL;

    first = new node();temp = new node();
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
    temp = first;
    first = reverse(temp);
    cout<<"\n";
    printlist(first);
 
    
    return 0;
}