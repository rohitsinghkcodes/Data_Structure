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

//deletion
struct CLL *deleteFront(struct CLL *head)
{
    struct CLL *temp = head,*curr = head;
    if (head == NULL)
    {
        printf("\n already Empty!");
        return head;
    }
    while (temp->next != head){
         temp = temp->next;
    }
    temp->next = head->next;
    if(head->next != head)      //more than single node
    {
        head = head->next;
    }else{
        head = NULL;        //only single node
    }
    
    printf("\n Deleted node: %d",curr->data);
    free(curr);
    return head;
}

struct CLL *deleteEnd(struct CLL *head)
{
    struct CLL *temp = head,*prev;
    if (head == NULL)
    {
        printf("\n already Empty!");
        return head;
    }
    while (temp->next != head){
        prev = temp;
         temp = temp->next;
    }

    if(temp!=head)
    {
        prev->next = temp->next;
    }
    else
    {
        head = NULL;
    }
    printf("\n Deleted node: %d",temp->data);
    free(temp);
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
            printf("\n Enter the data to be stored in front: ");
            scanf("%d", &d);
            head = insertEnd(head, d);
            break;
        case 3:
            printf("\n deleting from front: ");
            head = deleteFront(head);
            break;
        case 4:
            printf("\n deleting from End: ");
            head = deleteEnd(head);
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