// Basics linkedlist creation

#include<stdio.h>
#include<stdlib.h>
struct LL
{
    int data;
    struct LL *next;
};

int main()
{
    struct LL *head;
    struct LL *second;
    struct LL *third;

    head = (struct LL *) malloc(sizeof(struct LL));
    second = (struct LL *) malloc(sizeof(struct LL));
    third = (struct LL *) malloc(sizeof(struct LL));

    head->data = 10;
    second->data = 20;
    third->data = 30;
    head->next = second;
    second->next = third;
    third->next = NULL;

    struct LL *temp;
    temp = (struct LL *) malloc(sizeof(struct LL));

    temp = head;
    // printing node values
    while (temp !=NULL)
    {
        printf("%d -- ",temp->data);
        temp = temp->next;
    }
    
    return 0;
}