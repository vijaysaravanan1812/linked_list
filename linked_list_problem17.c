//quick sort in linked list

#include<stdio.h>
#include<stdlib.h>
#include"lib.c"


node Get_Tail(node temp)
{
    while (temp ->next != NULL && temp != NULL)
    {
        temp = temp ->next;
    }
    return temp;
}


node Partition(node head,node end,node *new_head,node *new_end)
{
    node pivot = end;
    node prev = NULL,current = head,tail = pivot;
    while (current != pivot)
    {
        if (current ->data < pivot->data)
        {
           
            if((*new_head) == NULL)
                (*new_head) = current;
             prev = current;//
            current = current->next;
        }
        else 
        {
            if (prev)
                prev->next = current->next;
            node temp = current->next;
            current->next = NULL;
            tail ->next = current;
            tail = current;
            current = temp;     
        }
    }
    
    if ((*new_head) == NULL)
        (*new_head) = pivot;

    (*new_end) = tail;

    return pivot;
}

node Quick_Sort(node head,node end)
{
    if (!head || head == end)
        return head;
    
    node new_head = NULL,new_end = NULL;
    node pivot = Partition(head,end,&new_head,&new_end);

    if (new_head != pivot)
    {
        node temp = new_head;
        while (temp->next != pivot)
            temp = temp ->next;
        temp ->next = NULL;

        new_head = Quick_Sort(new_head , temp);

        temp = Get_Tail(new_head);
        temp->next = pivot;
    }

    pivot->next = Quick_Sort(pivot->next,new_end);

    return new_head;
    

}

node Sort(node *head)
{
    (*head) = Quick_Sort(*head, Get_Tail(*head));

}

int main()
{
    insert(23,1);
    insert(34,2);
    insert(15,3);
    insert(03,4);
    insert(12,5);
    insert(22,6);
    print_list(start);
    Sort(&start);
    print_list(start);



}