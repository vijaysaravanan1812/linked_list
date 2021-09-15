
//11) print the linked list in reverse order
#include<stdio.h>
#include<stdlib.h>
#include"lib.c"

void printlist(node temp)
{
    if (temp == NULL)
        return;
    printlist(temp ->next);
    printf("%d \t",temp->data);
}

int main()
{
    insert(12,3);
    insert(15,2);
    insert(34,3);
    insert(63,4);
    printf("Given list\n");
    print_list(start);
    printf("Reverse order\n");
    printlist(start);
    printf("\n");
}