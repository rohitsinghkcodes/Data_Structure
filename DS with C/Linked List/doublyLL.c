#include <stdio.h>
#include <stdlib.h>

struct DllNode
{
    int data;
    struct DllNode *prev;
    struct DllNode *next;
};

struct DllNode *insertBegin(struct DllNode *head, int data)
{
    struct DllNode *curr = head;
    struct DllNode *new = (struct DllNode *)malloc(sizeof(struct DllNode));
    if (!new)
    {
        printf("\nMemory Error!");
        return head;
    }
    new->prev = NULL;
    new->data = data;
    new->next = NULL;

    if (curr == NULL) //no previous node
    {
        head = new;
        return head;
    }

    //already some node exits
    new->next = head;
    head->prev = new;
    head = new;
    return head;
}

struct DllNode *insertEnd(struct DllNode *head, int data)
{
    struct DllNode *new = (struct DllNode *)malloc(sizeof(struct DllNode));
    struct DllNode *curr = head;
    if (!new)
    {
        printf("\nMemory Error!");
        return head;
    }
    new->prev = NULL;
    new->data = data;
    new->next = NULL;

    if (head == NULL)
    {
        head = new;
        return head;
    }

    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = new;
    new->prev = curr;
    return head;
}

struct DllNode *insertAtPosition(struct DllNode *head, int data, int pos)
{
    struct DllNode *new = (struct DllNode *)malloc(sizeof(struct DllNode));
    struct DllNode *temp = head;
    //pos--;
    if (!new)
    {
        printf("\nMemory Error!");
        return head;
    }

    new->prev = NULL;
    new->data = data;
    new->next = NULL;

    if (pos <= 1)
    {
        new->next = head;
        if (head)
        {
            head->prev = new;
        }
        head = new;
        return head;
    }

    int k = 1;
    while (k < pos - 1 && temp->next != NULL)
    {
        temp = temp->next;
        k++;
    }
    if (k < pos - 1)
    {
        printf("\n positon not available!");
        return head;
    }

    new->next = temp->next;
    new->prev = temp;
    if (temp->next)
    {
        temp->next->prev = new;
    }
    temp->next = new;
    return head;

    // Another method
    // while(pos-- && temp!=NULL)
    // {
    //     temp=temp->next;
    // }
    // if(temp == NULL)
    // {
    //     printf("\n positon not available!");
    //     return head;
    // }
    // else{
    //     new->next = temp->next;  //if last node it will store null
    // new->prev = temp;
    // if(temp->next)
    // {
    //     temp->next->prev = new;
    // }
    // temp->next = new;
    // }
    // return head;
}

//for traversing in the linked list
void llTraversal(struct DllNode *head)
{
    printf("\n*****************************************************\n\n");
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

struct DllNode *deleteFront(struct DllNode *head)
{
    struct DllNode *temp;
    if (head == NULL)
    {
        printf("\nAlready empty!");
        return NULL;
    }

    temp = head;
    printf("\n Deleted node: %d", temp->data);
    head = head->next;

    if (head != NULL)
    {
        head->prev = NULL;
    }

    free(temp);
    return head;
}
struct DllNode *deleteEnd(struct DllNode *head)
{
    struct DllNode *temp, *current = head;
    if (head == NULL)
    {
        printf("\n Empty List");
        return head;
    }
    while (head->next != NULL)
    {
        head = head->next;
    }
    current = head->prev;
    if (current != NULL)
    {
        current->next = head->next;
    }
    printf("\n Deleted node: %d", head->data);
    free(head);
    return current;
}

struct DllNode *deletePosition(struct DllNode *head, int pos)
{
    struct DllNode * temp,* temp2;
    int k=1;
    if(head == NULL)
    {
        printf("\nList is Empty");
        return head;
    }
    
    if(pos <= 1)
    {
        temp = head;
        
        head = head->next;
        if(head!=NULL)
        {
            head->prev = NULL;
        }
         printf("\n Deleted node: %d", temp->data);
        free(temp);
        return head;
    }
    temp = head;
    while(k<pos && temp->next!=NULL)
    {
        temp = temp->next;
        k++;
    }
    if(k <pos)
    {
        printf("\nposition does not exist");
        return head;
    }
    temp2 = temp->prev;
    temp2->next = temp->next;
    if(temp->next !=NULL)
    {
        temp->next->prev = temp2;
    }
    printf("\n Deleted node: %d", temp->data);

    free(temp);
    return head;
}

int main()
{
    struct DllNode *head = NULL;
    int d, p;
    while (1)
    {
        int ch;

        printf("\n\n*****************************************************\nSelect \n \t 1 : Inserting node in the beginning.\n \t 2 : Inserting node at the end.\n \t 3 : Inserting node at a perticular position.\n \t 4 : Deleting node in the beginning.\n \t 5 : Deleting node at the end.\n \t 6 : Deleting node at a perticular position.\n \t 7 : Displaying Linked List elements.\n \t 8 : Exit \n Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\n Enter the data to be stored in beginning: ");
            scanf("%d", &d);
            head = insertBegin(head, d);
            break;
        case 2:
            printf("\n Enter the data to be stored at end: ");
            scanf("%d", &d);
            head = insertEnd(head, d);
            break;
        case 3:
            printf("\n Enter the position and data: ");
            scanf("%d %d", &p, &d);
            head = insertAtPosition(head, d, p);
            break;
        case 4:
            printf("\n Deleting from the front ");
            head = deleteFront(head);
            break;
        case 5:
            printf("\n Deleting from last element ");
            head = deleteEnd(head);
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