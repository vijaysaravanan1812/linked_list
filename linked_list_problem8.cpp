//Rotation of linked list
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



void rotate_list(node *head)
{
    int n;
    cout<<"How many rotations"<<"\t";
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        node *current_node = NULL,*prev_node = NULL;
        current_node = new node();
        prev_node = new node();
        current_node = head;
        while (current_node -> next != NULL)
        {
            prev_node  = current_node;
            current_node  = current_node ->next;
        }
        prev_node ->next = NULL;
        current_node ->next = head;
        head = current_node;
    }
    printlist(head);
 

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
    rotate_list(first);
  
}