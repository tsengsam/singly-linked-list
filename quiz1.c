#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
typedef struct __node
{
    int value;
    struct __node *next;
} node_t;

void add_entry(node_t **head, int new_value)
{
    node_t **indirect = head;

    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->value = new_value;
    new_node->next = NULL;

    assert(new_node);
    while (*indirect)
        indirect = &(*indirect)->next;
    *indirect = new_node;
}
/*
void add_entry(node_t *head, int new_value)
{
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->value = new_value;
    new_node->next = NULL;
    assert(new_node);

    if (head == NULL)
    {
        printf("aaaaa\n");
        head = new_node;
    }
    else
    {
        printf("bbbbb\n");
        node_t *tmp = head;
        while (tmp->next)
        {
            tmp = tmp->next;
        }
        tmp->next = new_node;
    }

    printf("addr of head in func = %p\n", head);
    printf("head->val = %d\n", head->value);
}*/
node_t *find_entry(node_t *head, int value)
{
    node_t *current = head;
    for (; current && current->value != value; current = current->next)
        /* interate */;
    return current;
}

void remove_entry(node_t **head, node_t *entry)
{
    node_t **indirect = head;

    while ((*indirect) != entry)
        indirect = &(*indirect)->next;

    *indirect = entry->next;
    free(entry);
}

/*void swap_pair(node_t *h)
{
    for (node_t **node = &h; *node && (*node)->next; node = &(*node)->next->next)
    {
        node_t *tmp = *node;
        *node = (*node)->next;
        tmp->next = (*node)->next;
        (*node)->next = tmp;
    }
}*/

void swap_pair(node_t **pp)
{
    for (node_t **node = pp; *node && (*node)->next; node = &(*node)->next->next)
    {
        node_t *tmp = *node;
        *node = (*node)->next;
        tmp->next = (*node)->next;
        (*node)->next = tmp;
    }
}

/*node_t *swap_pair(node_t *h)
{
    for (node_t **node = &h; *node && (*node)->next; node = &(*node)->next->next)
    {
        node_t *tmp = *node;
        *node = (*node)->next;
        tmp->next = (*node)->next;
        (*node)->next = tmp;
    }
    return h;
}*/

/*node_t *reverse(node_t *head)
{
    node_t *cursor = NULL;
    while (head)
    {
        node_t *next = head->next;
        head->next = cursor;
        cursor = head;
        head = next;
    }
    return cursor;
}*/

node_t *rev_recursive(node_t *h)
{
    if(!h || h->next == NULL)
    {
        return h;
    }
    node_t *cursor = rev_recursive(h->next);
    node_t *tmp = cursor;
    while(tmp->next)
    {
        tmp = tmp->next;
    }
    tmp->next = h;
    h->next = NULL;
    return cursor;
}

/*node_t *reverse(node_t *head)
{
    return rev_recursive(head);
}
*/

void reverse(node_t **pp)
{
    node_t *cursor = NULL;

    while (*pp)
    {
        node_t *next = (*pp)->next;
        (*pp)->next = cursor;
        cursor = *pp;
        *pp = next;
    }
    *pp = cursor;
}

void print_list(node_t *head)
{
    for (node_t *current = head; current; current = current->next)
        printf("%d ", current->value);
    /*while(head)
    {
        printf("%d ", head->value);
        head = head->next;
    }*/
    printf("\n");
}

void FYshuffle(node_t **h)
{
    /*Calculate length of linked list*/
    int len = 0;
    
    node_t **pivot = h;
    for (; *pivot; pivot = &(*pivot)->next)
        ++len;

    pivot = h;
    for (int i = len; i>1; i--) {
        /*Pick a random number k from 1 to i*/
        int k = (rand() % i) + 1;
	/*Find the kth node*/
	node_t **kNode = pivot;
	while (k>1) {
		kNode = &(*kNode)->next;
		k--;	
	}
	/*Swap values of pivot node and kNode*/
	int val = (*pivot)->value;
	(*pivot)->value = (*kNode)->value;
	(*kNode)->value = val;

	pivot = &(*pivot)->next;
    }
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    node_t *head = NULL;
    //print_list(head);
    add_entry(&head, 1);
    add_entry(&head, 2);
    add_entry(&head, 3);
    add_entry(&head, 4);
    print_list(head);
    //node_t *entry = find_entry(head, 101);
    //remove_entry(&head, entry);

    //entry = find_entry(head, 111);
    //remove_entry(&head, entry);

    //print_list(head);
    //head = swap_pair(head);
    //swap_pair(head);
    //print_list(head);

    //head = reverse(head);
    //reverse(&head);
    //print_list(head);
    FYshuffle(&head);
    print_list(head);

    return 0;
}
