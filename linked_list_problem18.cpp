// Given the heads of two singly linked-lists headA and headB, 
// return the node at which the two lists intersect. 
// If the two linked lists have no intersection at all, return null.

#include<iostream>
#include<math.h>

using namespace std;

struct node
{
    int data;
    node* next;
};

node * find_intersection(node *& head1 , node *& head2)
{
    int len1 = 0, len2 = 0;
    for (node * temp  = head1; temp != NULL; temp= temp->next)
        len1++;
    for (node * temp = head2; temp != NULL; temp = temp->next)
        len2++;


    node * temp1 = head1,* temp2 = head2;
    int x = abs(len1 - len2);
    if (len1 >= len2)
    {
        for (int i = 0; i < x; i++)
        {
            temp1 = temp1->next;
        }
        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1 == temp2)
                return temp1;
            temp1 = temp1 ->next;
            temp2 = temp2->next;
        }
    }
    else
    {
        for (int i = 0; i < x; i++)
        {
            temp2 = temp2->next;
        }
        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1 == temp2)
                return temp1;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
    }
    return NULL;
    
}


int main()
{
    node* head1 = new node;
    head1->data = 1;
    head1->next = new node;
    head1->next->data = 2;
    head1->next->next = new node;
    head1->next->next->data = 3;
    head1->next->next->next = new node;
    head1->next->next->next->data = 4;
    head1->next->next->next->next = new node;
    head1->next->next->next->next->data = 5;
    node* head2 = new node;
    head2->data = 11;
    head2->next = new node;
    head2->next->data = 15;
    head2->next->next = new node;
    head2->next->next->data = 17;
    head2->next->next->next = head1->next;

    node * temp = head1;
    while (temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp ->next; 
    }
    printf("\n");

    temp = head2;
    while (temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp ->next; 
    }
    printf("\n");

    cout<<"intersection node is "<<(find_intersection(head1,head2))<<"\n";
    
}