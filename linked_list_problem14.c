
// 14) count occurrences in a linked list 
#include"lib.c"


int count_occurrences(node *head,int key)
{
    node temp = *head;int count = 0;
    while (temp != NULL)
    {
        if (temp ->data == key)
            count ++;
        
        temp = temp ->next;
    }
    return count;
    
}

int main()
{
    insert(12,1);
    insert(24,2);
    insert(14,3);
    insert(12,4);
    insert(43,5);
    insert(12,6);
    insert(34,2);
    insert(12,4);
    insert(34,2);

    print_list(start);
    printf("Number of occurrence of 12 is %d \n",count_occurrences(&start , 12));
    printf("Number of occurrence of 34 is %d \n",count_occurrences(&start , 34));
    printf("Number of occurrence of 14 is %d \n",count_occurrences(&start , 14));
}



