
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
    node *temp =NULL;int count =0;
    temp = new node();
    temp = head;
    while (temp ->next != 0)
    {
        temp = temp ->next;
        if (count == index)
        {
            return temp ->data;
        }
        count++;
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
    
    node *first = NULL;   node *newnode;
    first = new node();   newnode = new node();  
    
    cin>>first ->data;
    first ->next = NULL;
  
    do
    {
        insert(first);
        cout<<"Do you add one more press Y or else press N";
        cin>>cho;

    } while (cho != 'N');
    cout<<"Given linked list";
    printlist(first);
    cout<<"Enter the index that you want"<<"\t";
    cin>>index;
    cout<<"index at "<<index<<" is "<<get_Nth_node(first , index);
    cout<<"\n";
    return 0;

}