//8) Rotation of linked list
using namespace std;

#include<iostream>
#include<stdlib.h>

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



node* rotate_list(node *head)
{
    int n;
    cout<<"How many rotations"<<"\t";
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        node *current_node = NULL,*prev_node = NULL;
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
    return head;
 

}

int main()
{
    printf("Enter the element for creating linked list\n");
    node *first = (struct node *) malloc(sizeof(struct node));
    node *second =  (struct node *)malloc(sizeof(struct node));
    node *third =   (struct node *)malloc(sizeof(struct node));
    node *fourth = (struct node *) malloc(sizeof(struct node));
    node *fifth =  (struct node *) malloc(sizeof(struct node));
    
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
    first = rotate_list(first);
    printlist(first);
}