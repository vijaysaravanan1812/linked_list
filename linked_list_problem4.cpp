using namespace std;

//searching node in linked list
#include<iostream>
struct node
{
    int data;
    node *next;
};
int  search(node *temp , int key)
{
    int i=0;
    while (temp != NULL)
    {
        if (key == temp ->data)
        {
            return i;
            break;
        }
        temp = temp ->next;
        i++;
    }
    return -1;
 
    
}

void printlist(node *temp)
{
    while (temp != NULL)
    {
        cout<<temp ->data<<" ";
        temp = temp ->next;

    }
    cout<<"\n";
}

void insert(node *temp)
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
    int key ; //element to be search
    
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
    cout<<"enter your key :"<<"\t";
    cin>>key;
    if (search(first,key) == -1)
    {
        cout<<"key not found"<<"\n";
    }
    else
    {
        cout<<"key found at position "<<search(first,key)<<"\n";
    }
    


    

}