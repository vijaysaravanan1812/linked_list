//4) searching node in linked list
#include<stdio.h>
#include<stdlib.h>
#include"lib.c"

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

int main()
{
    int key ; //element to be search

    insert(10,1);
    insert(12,2);
    insert(14,3);
    insert(16,4);
    
    printf("Given linked list\n");
    print_list(start);
    printf("Enter the key\t");
    scanf("%d",&key);
    if (search(start,key) == -1)
    {
        printf("Element not Found\n");
    }
    else
    {
        printf("Key found at %d \n",search(start,key));
    }
    


    

}