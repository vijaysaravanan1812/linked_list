
//12) swap the two nodes that given by users in linked list 

#include<stdio.h>
#include<stdlib.h>
#include"lib.c"


void swapNodes(node *head_ref, int x, int y) 
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

int main()
{
    insert(12,3);
    insert(15,2);
    insert(34,3);
    insert(63,4);
    insert(35,5);
    insert(62,6);
    insert(72,7);
    printf("Given list\n");
    print_list(start);
    printf("After the nodes that contain 12 and 34 going to swap\n");
    swapNodes(&start, 12 , 34);
    print_list(start);
    printf("After the nodes that contain 62 and 15 going to swap\n");
    swapNodes(&start, 62 , 15);
    print_list(start);
    printf("After the nodes that contain 34 and 72 going to swap\n");
    swapNodes(&start, 34, 72);
    print_list(start);
    return 0;
}