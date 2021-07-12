#include <stdio.h>
#include <stdlib.h>

struct CLL
{
    int data;
    struct CLL *next;
};

struct CLL *insertFront(struct CLL *head, int data)
{
    struct CLL *new = (struct CLL *)malloc(sizeof(struct CLL));
    struct CLL *temp = head;
    if (!new)
    {
        printf("\n Memory Error!");
        return head;
    }

    new->data = data;
    new->next = new; //self loop in the next

    if (head == NULL)
    {
        head = new;
        return head;
    }

    while (temp->next != head){
         temp = temp->next;
    }
    

    temp->next = new;
    new->next = head;
    head = new;
    return head;
}


struct CLL *insertEnd(struct CLL *head, int data)
{
    struct CLL *new = (struct CLL *)malloc(sizeof(struct CLL));
    struct CLL *temp = head;
    if (!new)
    {
        printf("\n Memory Error!");
        return head;
    }

    new->data = data;
    new->next = new; //self loop in the next

    if (head == NULL)
    {
        head = new;
        return head;
    }

    while (temp->next != head){
         temp = temp->next;
    }
    

    temp->next = new;
    new->next = head;
    return head;
}
//Traversal
void llTraversal(struct CLL *head)
{
    struct CLL * temp = head;
    printf("\n*****************************************************\n\n");
    if (head == NULL)
    {
        printf("\n SORRY!! NO NODES. PLEASE INSERT SOME.");
        return;
    }

    do
    {
        printf("%d -- ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main()
{
    struct CLL *head = NULL;
    int d;
    while (1)
    {
        int ch;

        printf("\n\n*****************************************************\nSelect \n \t 1 : Inserting node in the beginning.\n \t 2 : Inserting node at the end.\n \t 3 : Deleting node in the beginning.\n \t 4 : Deleting node from the end.\n \t 5 : Displaying Linked List elements.\n \t 6 : Exit \n Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\n Enter the data to be stored in beginning: ");
            scanf("%d", &d);
            head = insertFront(head, d);
            break;
        case 2:
            printf("\n Enter the data to be stored in beginning: ");
            scanf("%d", &d);
            head = insertEnd(head, d);
            break;
        case 5:
            printf("\n The linked list elements are: \n ");
            llTraversal(head);
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("\nWrong choice!");
            break;
        }
    }

    return 0;
}