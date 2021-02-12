//10) geting nth index element

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

int get_Nth_node(node *head ,int index)
{
    node *temp =NULL;int count = 1;
    temp = new node();
    temp = head;
    while (temp  != NULL)
    {
       
        if (count == index)
        {
            return temp ->data;
        }
        count++;
        temp = temp ->next;
    }
    
}



void insert(node *temp )
{
    node *nextnode;
    nextnode = new node();
    cin>>nextnode -> data;
    nextnode ->next = NULL;
    while ( temp ->next != NULL)
    {
        temp = temp ->next;
    }
    temp ->next =  nextnode ;
}

int main()
{
    char cho; //Ask choice
    int index;
    
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
  
    cout<<"Given linked list"<<"\t";
    printlist(first);
    cout<<"Enter the index that you want"<<"\t";
    cin>>index;
    cout<<"index at "<<index<<" is "<<get_Nth_node(first , index);
    cout<<"\n";
    return 0;

}