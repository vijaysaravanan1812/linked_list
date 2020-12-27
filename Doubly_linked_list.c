// creating doubly linked list (global declaration)

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *right;
    struct node *left;
};
typedef struct node * node;
node start = NULL,last = NULL,temp = NULL;

void insert(int pos)
{
    int i = 1;
        node new_node;
        new_node =  (struct node *) malloc(sizeof (struct node));
        printf("Enter the element\t"); 
        scanf("%d",&new_node->data);
    if (start == NULL && last == NULL)
    {
        start = last = new_node;
        start ->right = NULL;
        start ->left = NULL;
    }   
    else if(start != NULL)
    {
        temp = start;
        while (temp ->right != NULL && i < pos - 1)
        {
            temp = temp ->right;
            i++;
        }
        if (pos == 1)
        {
            new_node ->right = start;
            new_node ->left = NULL;
            start ->left = new_node;
            start = new_node;
        }
        else if (temp ->right == NULL)
        {
            new_node ->right = NULL;
            new_node ->left = temp;
            temp ->right = new_node;
            last = new_node ;
            
        }
        else
        {
            new_node ->right = temp->right;
            new_node ->left = temp;
            (temp->right)->left = new_node;
            temp->right = new_node;
        }
    }
    getchar();
}

void delete_node(int element)
{
    if (start != NULL)
    {
        temp = start;
        while (temp != NULL && temp->data != element)
        {
            temp = temp->right;
        }
        if (temp == NULL)
        {
            printf("NO SUCH ELEMENT FOUND\n");
        }
        else
        {
            printf("Element Deleted\n");
            if (start == last)
            {
                start = last = NULL;
                free(temp);
            }
            
            else if (start->data == element)
            {
                start = start ->right;
                start ->left = NULL;
                free(temp);
            }
            else if (last ->data == element)
            {
                last = last->left;
                last ->right = NULL;
                free(temp);
            }
            else
            {
                (temp->left)->right = temp->right;
                (temp->right)->left = temp ->left;
                free(temp);
            }
        }
        getchar();
        
    }
    
}

void display()
{
    temp = NULL;
    if (start != NULL)
    {
        printf("linked list\n");
        temp = start;
        while (temp != NULL)
        {
            printf("%d\t",temp->data);
            temp = temp->right;
        }
        printf("\nreverse order\n");
        temp = NULL; temp = last;
        while (temp != NULL)
        {
            printf("%d\t",temp->data);
            temp = temp->left;
        }printf("\n");
        getchar();
    }
    else
    {
        printf("NO HERE TO PRINT\n");
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
            printf("Enter the position\t");
            scanf("%d",&pos);

            insert(pos);
        }
        else if (choice == 2)
        {
            display();
        }
    /*  else if (choice == 3)
        {
            delete();
        }*/
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