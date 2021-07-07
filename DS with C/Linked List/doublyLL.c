#include<stdio.h>
#include<stdlib.h>

struct DllNode{
    int data;
    struct DllNode * prev;
    struct DllNode * next;
};

//for traversing in the linked list
void llTraversal(struct DllNode *head)
{
    if (head == NULL)
    {
        printf("\n SORRY!! NO NODES. PLEASE INSERT SOME.");
    }
    while (head != NULL)
    {
        printf("%d -- ", head->data);
        head = head->next;
    }
}


int main()
{
    struct DllNode * head,* second, *third;
    head = (struct DllNode *)malloc (sizeof(struct DllNode));
    second = (struct DllNode *)malloc (sizeof(struct DllNode));
    third = (struct DllNode *)malloc (sizeof(struct DllNode));
    head->prev = NULL;
    head->data = 10;
    head->next = second;
    second->prev = head;
    second->data = 20;
    second->next = third;
    third->prev = second;
    third->data = 30;
    third->next = NULL;

    llTraversal(head);

}