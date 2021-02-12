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
    node* previous_node = NULL ;
    node* current_node ;
    node* next_node ;

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
    return head;

}

int main()
{
    node *first = new node(), *temp = new node();
    node *second = new node();
    node *third = new node();
    node *fourth = new node();
    node *fifth = new node();

    first ->data = 2;
    first ->next = second;

    second ->data = 4;
    second ->next = third;

    third ->data = 6;
    third ->next = fourth;

    fourth ->data = 8;
    fourth ->next = fifth;

    fifth -> data = 10;
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