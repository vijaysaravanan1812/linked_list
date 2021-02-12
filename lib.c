//library functions for linked list

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

typedef struct node * node;
node start = NULL,last = NULL;

void print_list(node temp)
{
    if (temp == NULL)
    {
        printf("NO LIST HERE TO PRINT \n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d \t",temp->data);
            temp = temp->next;
        }printf("\n");
        
    }
    
    
}


void insert(int data,int pos)
{
    int i = 1;node temp = NULL;
    node new_node =  (node)malloc(sizeof(struct node));
    new_node ->data = data;
    if (start == NULL && last == NULL)
    {
        start = last = new_node;
        new_node ->next = NULL;
    }
    else
    {
        temp = start;
        while (temp != NULL && i < pos - 1)
        {
            temp = temp ->next;
            i++;
        }
        if (pos == 1)
        {
            new_node ->next = start;
            start = new_node;
        }
        else if (temp == NULL)
        {
            last ->next = new_node;
            new_node->next = NULL;
            last = new_node;
        }
        else
        {
            new_node ->next = temp->next;
            temp ->next = new_node;
        }
    }
}

void delete()
{
    if (start == NULL)
    {
        printf("NO LIST HERE TO PRINT\n");
    }
    else
    {
        printf("LIST DELETED\n");
        node prev,temp;
        prev = temp = start;
        while (temp != NULL)
        {
            temp = temp->next;
            free(prev);
            prev = temp;
        }
        start = last = NULL;
    }
    
    
}

void delete_node(int element)
{
    if (start == NULL)
        printf("NO ELEMENT TO DELETE\n");
    else
    {
        node prev, temp;
        prev = temp = start;
        while (temp ->data != element && temp->next != NULL)
        {
            prev = temp;
            temp = temp ->next;
        }
        if (temp ->next == NULL && temp ->data != element)
            printf("ELEMENT NOT FOUND\n");
        else
        {
            printf("ELEMENT DELETED\n");
            if(start == last)
            {   
                start = last = NULL;
                free(temp);
            }
            else if(start ->data == element)
            {
                start = start ->next;
                free(temp);
            }

            else
            {
                prev ->next = temp->next;
                free(temp);
            }

        }
    }
}

int length(node temp)
{
    int i=1;
    while ( temp->next  != NULL)
    {
        temp = temp ->next;
        i++;
    }
    return i;
}

