
//creating linked list using global pointer variables that contain all operation
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node *node;
node temp = NULL ,start = NULL,last = NULL;

void insert(int pos)
{
    int i = 1;
        node new_node;
        new_node = (struct node *) malloc(sizeof(struct node));
        printf("Enter your data\n");
        scanf("%d",&new_node->data);
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
            temp = temp->next;
            i++;
        }
        if (pos == 1)
        {
            new_node ->next = start;
            start = new_node;
        }
        else if (temp == NULL)
        {
            new_node ->next = NULL;
            last ->next = new_node;
            last = new_node;
        }
        else
        {
            new_node ->next = temp ->next;
            temp ->next = new_node;
        }
    }
    
}

void delete()
{
    node prev;
    start = prev = temp;
    while (temp != NULL)
    {
        temp = temp->next;
        free(prev);
        prev = temp ;
    }
    start = last = NULL;
}

void delete_node(int element)
{
    {
        printf("ELEMENT DELETED\n");
        node prev;
        prev = temp = start;
        while (temp->data != element && temp != NULL )
        {
            prev = temp;
            temp = temp ->next;
        }
        if (temp == NULL)
            printf("Element not found\n");
        else if (last == start)
        {
            start = last = NULL;
            free(temp);
        }
        else if (start ->data == element)
        {
            start = start ->next;
            free(temp);
        }    
        else
        {
            prev ->next = temp ->next;
            free(temp);
        }
        getchar();
    }
}

void display()
{
    if (start != NULL)
    {
        temp = start;
        while (temp != NULL)
        {
            printf("%d\t",temp ->data);
            temp  = temp ->next;
        }
        getchar();
        printf("\n");
    }
    else
    {
        printf("NO LIST HERE TO PRINT\n");
        getchar();
    }
    
    
}


int main()
{
    system("clear");
    do
    {
        int choice,pos;
        printf("Isertion - 1\nDisplay - 2\nDelete - 3\nDelete node - 4\nExit - 0\n");
        scanf("%d",&choice);
        if(choice == 1)
        {
            printf("Enter the position\n");
            scanf("%d",&pos);

            insert(pos);
        }
        else if (choice == 2)
        {
            display();
        }
        else if (choice == 3)
        {
            delete();
        }
        else if (choice == 4)
        {
            int element;
            if (start == NULL && last == NULL)
            {
                printf("NO list HERE TO DELETE\n");
                getchar();
            }
            else
            {
                printf("Enter the element to delete\n");
                scanf("%d",&element);
                delete_node(element);
            }
        }
        else if (choice == 0)
            break;
        getchar();
        system("clear");
    } while (1);
    
}