//Detect the loop in linked list 
//6)To calculate length of loop
using namespace std;
#include<iostream>

struct node
{
    int data;
    node *next;
};
int count_loop_length(node *n)
{
    node *temp = n;
    int i =1;
    while (temp -> next != n)
    {
        i++;
        temp = temp ->next;
    }
    return i;

    
}

int detectloop(node *head)
{
    node *fast = NULL,*slow = NULL;
    slow = new node();
    fast = new node();
    slow = head;fast = head;
    int i=1;
    while (slow && fast && fast->next )
    {
        slow = slow->next;
        fast = fast ->next ->next;
        i++;
        if (slow == fast)
        {
            return count_loop_length(slow);
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
    fifth ->next = second; 

    if (detectloop(first) != 1)
    {
        cout<<"Given liked list has loop"<<"\n"<<"Then loop length is : "<<detectloop(first)<<"\n";
    }
    else
    {
        cout<<"Given linked list has no loop"<<"\n";
    }
    
    

    return 0;
}