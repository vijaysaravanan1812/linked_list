
// 13) print the middle element of the linked list
#include<stdio.h>
#include<stdlib.h>
#include"lib.c"

void print_middle(node head)
{
    node fast,slow;
    slow = fast = head;
    if (head != NULL)
    {
        while (fast && fast->next )
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        printf("The middle element is %d\n",slow->data);
    }
    
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
    insert(36,4);
    printf("The given list is \n");
    print_list(start);

    print_middle(start);
}