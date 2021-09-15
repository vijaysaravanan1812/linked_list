//15)  Find n'th node from end

#include"lib.c"

node get_nth_node_from_last(node head,int n)
{
    if (head == NULL)
        return NULL;
    static int i = 0;
    get_nth_node_from_last(head->next,n);
    if (++i == n)
    {
        printf("%d \n",head->data);
    }
    
}



int main()
{
    insert(29,1);insert(34,2);
    insert(24,3);insert(26,4);   
    insert(28,1);insert(39,2);
    insert(14,3);insert(20,4);
    print_list(start);
    get_nth_node_from_last(start,3);

}