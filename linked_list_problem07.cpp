//7) Delete the duplicate element in sorted linked list
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
                free(current_node->next->next);
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
    printf("Given linked list\n");
    printlist(first);
    printf("After Removing duplicates\n");
    delete_duplicates(first);
    printlist(first);
  
}