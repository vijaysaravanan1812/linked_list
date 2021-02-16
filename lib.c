
#include<stdio.h>
#include<stdlib.h>

//library functions for linked list

struct node
{
    int data;
    struct node* next;
};

/*node is a data type that creating pointer 
struct node
{
    int data;
    struct node* next;
};
typedef struct node * node;
node start = NULL,last = NULL;

start and last are pointer in 'node' data type which is used in this file
*/
typedef struct node * node;
node start = NULL,last = NULL;

//Function to print the linked list
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

//By default 'start' represent first node of linked list and 'last' represent last node of linked list
//Function to insert a node at any position in linked list
//pass data and position as argument 
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

//Function to entire linked list list
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

//function to delete the given node
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

//Function to count the length of list
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

//Function to reverse the links in list 
// pass the address of start node
node reverse(node* head)
{ 
    node previous_node = NULL ;
    node current_node ;
    node next_node ;

    current_node = *head;
    next_node = *head;
    while (next_node != NULL)
    {
        next_node = next_node ->next;
        current_node ->next = previous_node;
        previous_node = current_node;
        current_node = next_node;
    }
    *head = previous_node;

}

//Function to search the node.
//return the index of element in linked list
int  search(node temp , int key)
{
    int i=1;
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

//Function to detect loop in list,pass the address of node
//pass the addrees of start node, if loop exist it return 1 otherwise it return -1
int isloop(node *head)
{
    node fast = NULL,slow = NULL;
    slow = (node)malloc(sizeof(struct node));
    fast = (node)malloc(sizeof(struct node));
    slow = *head;fast = *head;
    while (slow && fast && fast->next )
    {
        slow = slow->next;
        fast = fast ->next ->next;
        if (slow == fast)
        {
            return 1;
        }
    }
    return -1;
}

//Function to count loop length.
    int count_loop_length(node n)
    {
        node temp = n;
        int i =1;
        while (temp -> next != n)
        {
            i++;
            temp = temp ->next;
        }
        return i;
    }
    
    //Function to count loop length.paas the address of node
    //it return the length of loop 
    //if list doesn't have loop it return -1
    int loop_length(node *head)
    {
        node fast = NULL,slow = NULL;
        slow =  (node)malloc(sizeof(struct node));
        fast = (node)malloc(sizeof(struct node));
        slow = *head;fast = *head;
        int i=1;
        while (slow && fast && fast->next )
        {  
            slow = slow->next;
            fast = fast ->next ->next;
            i++;
            if (slow == fast)
            {
                return count_loop_length(slow);
            }
        }
        return -1;
    }

//Function to rotate the list.
//pass address of node and number of rotations.
node rotate_list(node *head, int n)
{
    for (int i = 0; i < n; i++)
    {
        node current_node = NULL,prev_node = NULL;
        current_node = *head;
        while (current_node -> next != NULL)
        {
            prev_node  = current_node;
            current_node  = current_node ->next;
        }
        prev_node ->next = NULL;
        current_node ->next = *head;
        *head = current_node;
    }
}


//Function to get node for given index
//pass the address of node and index
int get_node(node *head ,int index)
{
    node temp =NULL;int count = 1;
    temp = *head;
    while (temp  != NULL)
    {
       
        if (count == index)
        {
            return temp ->data;
        }
        count++;
        temp = temp ->next;
    }
    return 0;
    
}


//Function to swap nodes
//pass address of node and data of nodes that going swap
void swap_nodes(node *head_ref, int x, int y) 
{ 
   // Nothing to do if x and y are same 
   if (x == y) return; 
  
   // Search for x (keep track of prevX and CurrX 
   node prevX = NULL, currX = *head_ref; 
   while (currX && currX->data != x) 
   { 
       prevX = currX; 
       currX = currX->next; 
   } 
  
   // Search for y (keep track of prevY and CurrY 
   node prevY = NULL, currY = *head_ref; 
   while (currY && currY->data != y) 
   { 
       prevY = currY; 
       currY = currY->next; 
   } 
  
   // If either x or y is not present, nothing to do 
   if (currX == NULL || currY == NULL) 
       return; 
  
   // zIf x is not head of linked list 
   if (prevX != NULL) 
       prevX->next = currY; 
   else // Else make y as new head 
       *head_ref = currY;   
  
   // If y is not head of linked list 
   if (prevY != NULL) 
       prevY->next = currX; 
   else  // Else make x as new head 
       *head_ref = currX; 
  
   // Swap next pointers 
   node temp = currY->next; 
   currY->next = currX->next; 
   currX->next  = temp; 
} 

//Function to get middle node in linked list
//pass the address of node
node get_middle_node(node *head)
{
    node fast,slow;
    slow = fast = *head;
    if (*head != NULL)
    {
        while (fast && fast->next )
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
}


node get_tail(node temp)
{
    while (temp ->next != NULL && temp != NULL)
    {
        temp = temp ->next;
    }
    return temp;
}


node partition(node head,node end,node *new_head,node *new_end)
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

//Function to sort linked list 
//pass the address of node
node sort(node *head);


node quick_sort(node head,node end)
{
    if (!head || head == end)
        return head;
    
    node new_head = NULL,new_end = NULL;
    node pivot = partition(head,end,&new_head,&new_end);

    if (new_head != pivot)
    {
        node temp = new_head;
        while (temp->next != pivot)
            temp = temp ->next;
        temp ->next = NULL;

        new_head = quick_sort(new_head , temp);

        temp = get_tail(new_head);
        temp->next = pivot;
    }

    pivot->next = quick_sort(pivot->next,new_end);

    return new_head;
    

}

node sort(node *head)
{
    (*head) = quick_sort(*head, get_tail(*head));

}






