//5) Detect the loop in linked list 
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
    fifth ->next = fourth; 

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