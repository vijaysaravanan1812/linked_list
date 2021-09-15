
//16) check whether given list is palindrome

#include"lib.c"
#include<stdbool.h>

bool ispal(node *left,node right)
{
    //if right pointer is NULL then return true
    if (right == NULL)
        return true;
    
    bool isp1 = ispal(left,right->next);

    if(isp1 == false)
        return false;

    bool isp = ((*left)->data == right->data);

    (*left) = (*left)->next;

    return isp;
}

bool ispalindrome(node head)
{
    return ispal(&head,head);
}

int main()
{
    insert(1,1);
    insert(2,1);
    insert(3,1);
    insert(2,1);
    insert(1,1);

    ispalindrome(start)?printf("It is palindrome\n"):printf("It not palindrome\n");
}