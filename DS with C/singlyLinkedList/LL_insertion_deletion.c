#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

//for inserting in the beginning
struct Node *insertAtBeginning(struct Node *head, int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = head;

    return temp; //returning new head
}

//for inserting at the end
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *new, *itr;
    new = (struct Node *)malloc(sizeof(struct Node));
    new->data = data;
    new->next = NULL;
    itr = head;

    //if no node node is present
    if (itr == NULL)
    {
        head = new;
    }

    else
    {

        while (itr->next != NULL)
        {
            itr = itr->next;
        }
        itr->next = new;
    }

    return head;
}

//for inserting after a perticular node position
struct Node *insertAtPosition(struct Node *head, int data, int pos)
{
    struct Node *temp, *prev;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    prev = head;
    if (pos <= 1)
    {
        temp->next = head;
        return temp;
    }
    else
    {
        while (--pos && prev != NULL)
        {
            prev = prev->next;
        }
        if (prev == NULL)
        {
            printf("\nposition not available");
            return NULL;
        }
        else
        {
            temp->next = prev->next;
            prev->next = temp;
        }
    }
    return head;
}

//deleting from front
struct Node *deleteFront(struct Node *head)
{
    struct Node *temp;
    if (head == NULL)
    {
        printf("\n Nothing to Delete! ");
        return NULL;
    }
    temp = head;
    head = head->next;
    printf("\n Deleted element: %d", temp->data);
    free(temp);
    return head;
}

//deleting from last
struct Node *deleteLast(struct Node *head)
{
    struct Node *temp = head, *prev;
    if (head == NULL)
    {
        printf("\nAlready empty!");
        return NULL;
    }
    else if (temp->next == NULL)
    {
        printf("\n Deleted element: %d", temp->data);
        head = NULL;
        free(temp);
        return head;
    }

    else
    {
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        printf("\n Deleted element: %d", temp->data);
        free(temp);
        return head;
    }
}

//deleting from position
struct Node *deletePosition(struct Node *head, int pos)
{
    struct Node *temp = head, *prev;
    if (head == NULL)
    {
        printf("\nAlready empty!");
        return NULL;
    }
    if (pos <= 1)
    {
        printf("\n Deleted element: %d", temp->data);
        head = head->next;
        free(temp);
        return head;
    }
    while (--pos && temp != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp ==NULL)
    {
        printf("\nposition not available");
        return head;
    }

    prev->next = temp->next;
    printf("\n Deleted element: %d", temp->data);
    free(temp);
    return head;
}
//for traversing in the linked list
void llTraversal(struct Node *head)
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
    struct Node *head = NULL;
    int d, p;
    while (1)
    {
        int ch;

        printf("\n\n*****************************************************\nSelect \n \t 1 : Inserting node in the beginning.\n \t 2 : Inserting node at the end.\n \t 3 : Inserting node at a perticular position.\n \t 4 : Deleting node in the beginning.\n \t 5 : Deleting node at the end.\n \t 6 : Deleting node at a perticular position.\n \t 7 : Displaying Linked List elements.\n \t 8 : Exit \n Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\n Enter the data to be stored: ");
            scanf("%d", &d);
            head = insertAtBeginning(head, d);
            break;
        case 2:
            printf("\n Enter the data to be stored: ");
            scanf("%d", &d);
            head = insertAtEnd(head, d);
            break;
        case 3:
            printf("\n Enter the data to be stored and position: ");
            scanf("%d %d", &p, &d);
            head = insertAtPosition(head, d, p);
            break;
        case 4:
            printf("\n Deleting from the front ");
            head = deleteFront(head);
            break;
        case 5:
            printf("\n Deleting from last element ");
            head = deleteLast(head);
            break;
        case 6:
            printf("\n Deleting element at positon x ");
            printf("\n Enter the position to delete node: ");
            scanf("%d", &p);
            head = deletePosition(head,p);
            break;
        case 7:
            printf("\n The linked list elements are: \n ");
            llTraversal(head);
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("\nWrong choice!");
            break;
        }
    }
}
