//9) pairwish swap the linked list
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



void pair_wise_swap(node *head)
{
    node *temp = NULL;int temp1;
    temp = new node();
    temp = head;
    while (temp ->next != NULL && temp != NULL)
    {
        temp1 = temp ->data;
        temp ->data = temp ->next ->data;
        temp ->next ->data = temp1;
        temp = temp ->next ->next;
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
    pair_wise_swap(first);
    printf("After pair swap\n");
    printlist(first);

    return 0;


  
}