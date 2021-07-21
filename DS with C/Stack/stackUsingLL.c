#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct LL
{
    int data;
    struct LL *next;
};

struct Stack
{
    struct LL *top;
};

//Empty stack creation
struct Stack *createStack()
{
    struct Stack *stk = malloc(sizeof(struct Stack));
    if (!stk)
    {
        printf("\n Memory Error!");
        return NULL;
    }
    stk->top = NULL;
    return stk;
}

int isEmpty(struct Stack *stk)
{
    return (stk->top == NULL);
}

//push fuction
void push(struct Stack *stk, int data)
{
    struct LL *temp = malloc(sizeof(struct LL));
    if (!temp)
    {
        printf("\nMemory Error!");
        return;
    }
    temp->data = data;
    temp->next = stk->top;
    stk->top = temp;
}

//pop functiion
int pop(struct Stack *stk)
{
    int data;
    struct LL *temp;
    if (isEmpty(stk))
    {
        printf("\nStack is Empty!");
        return INT_MIN;
    }
    temp = stk->top;
    stk->top = stk->top->next; //updating top
    data = temp->data;
    free(temp);
    return data;
}

int size(struct Stack *stk)
{
    int s = 0;

    if (isEmpty(stk))
    {
        return 0;
    }
    struct LL *temp = stk->top;
    while (temp)
    {
        s++;
        temp = temp->next;
    }
    return s;
}

int peek(struct Stack *S)
{
    if (isEmpty(S))
    {
        printf("\nStack is Empty!");
        return INT_MIN;
    }
    return (S->top->data);
}

void printStack(struct Stack * S)
{
    struct LL * temp = S->top;
    if(isEmpty(S))
    {
        printf("\nStack is Empty");
        return;
    }
    printf("\nPrinting stack: \n");
    while(temp)
    {
        printf("|| %d ||\n",temp->data);
        temp=temp->next;
    }

}

int main()
{
    int data;
    struct Stack *S = createStack();
    while (1)
    {
        int choice;
        printf("\n\n1. push() \n2. pop()\n3. size()\n4. peek\n5. print stack\n6. exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the data to be pushed on to the stack: ");
            scanf("%d", &data);
            push(S, data);
            break;
        case 2:
            printf("\nThe popped element from the stack is: %d", pop(S));
            break;
        case 3:
            printf("\nsize of current stack: %d", size(S));
            break;
        case 4:
            printf("\nthe topmost element of stack is: %d", peek(S));
            break;
        case 5:
            printStack(S);
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("\nWrong Choice!");
            break;
        }
    }
    return 0;
}