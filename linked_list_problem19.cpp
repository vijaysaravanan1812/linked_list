//19) merge two sorted list

#include<iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};

node * merge(node *& head1, node *& head2)
{
    
    int len1 = 0, len2 = 0;
    node * temp1 = head1,* prev1 = NULL;
    node * temp2 = head2,* prev2 = NULL;
    for (node * temp  = head1 ; temp != NULL; temp = temp->next)
        len1++;
    for (node *temp  = head2; temp !=   NULL; temp = temp ->next)
        len2++;

    while (temp1 != NULL && temp2 != NULL)
    {
        if(temp2->data <= temp1->data)
        {   
            prev2 = temp2->next;
            temp2->next = temp1;
            if (temp1 == head1)
            {
                head1 = temp2;
            }
            
            temp1 = temp1->next;
            temp2 = prev2;
        }
        else
        {
            prev2 = temp2->next;
            temp2->next = temp1->next;
            temp1->next = temp2;
            temp1 = temp1->next->next;
            temp2 = prev2;
        }
    }
    
    


    
}

int main()
{
    node * head1                    = new node;
    head1->next                     = new node;
    head1->next->next               =  (node *)malloc(sizeof(node ));
    head1->next->next->next         =  (node *)malloc(sizeof(node ));
    head1->next->next->next->next   =  (node *)malloc(sizeof(node ));
    head1->next->next->next->next->next = NULL;
    node * head2                    = new node;
    head2->next                     = new node;
    head2->next->next               =  (node *)malloc(sizeof(node ));
    head2->next->next->next         =  (node *)malloc(sizeof(node ));
   head2->next->next->next->next   =  (node *)malloc(sizeof(node ));
    head2->next->next->next->next->next = NULL;
    head1->data                             = 12;
    head1->next->data                       = 24;
    head1->next->next->data                 = 36;
    head1->next->next->next->data           = 48;
    head1->next->next->next->next->data     = 60;
    head2->data                             = 22;
    head2->next->data                       = 34;
    head2->next->next->data                 = 46;
    head2->next->next->next->data           = 58;
    head2->next->next->next->next->data     = 70;

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

    merge(head1,head2);

     temp = head1;
    while (temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp ->next; 
    }
    printf("\n");







}