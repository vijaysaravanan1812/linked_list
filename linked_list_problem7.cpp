//Delete the duplicate element in sorted linked list
using namespace std;

#include<iostream>

struct node
{
    int data ;
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
void delete_duplicates(node *head)
{
    node *current_node = NULL,*temp  = NULL;
    temp = new node();
    current_node = new node();

    current_node = head;
    while (current_node ->next != NULL)
    {
        if (current_node ->data == current_node ->next->data )
        {
            if (current_node ->data == current_node ->next ->next->data )
            {
                temp = current_node ->next ->next ->next;
                current_node ->next = temp;
            }
            else
            {
                temp = current_node ->next ->next;
                free(current_node->next);
                current_node ->next = temp;
            }
        }
        else
        {
             current_node = current_node ->next;
        }
        
        
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

    

    delete_duplicates(first);
    printlist(first);
  
}