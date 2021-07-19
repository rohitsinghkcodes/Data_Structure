#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Stack{
    int top;
    int capacity;
    int *array;
};

struct Stack * createStack(int capacity)
{
    struct Stack * S = malloc(sizeof(struct Stack));
    //if Memory is not allocated
    if(!S){
        printf("\n Memory Error!");
        return NULL;
    }

    S->capacity = capacity;
    S->top = -1;
    S->array = malloc(S->capacity * sizeof(int));
    if(!S->array){
        printf("\nMemory Error in creating array!");
        return NULL;
    }
    return S;
}

//checking if the stack is empty ot not
int isEmpty(struct Stack * S)
{
    return(S->top==-1);
}

//returns the size of the current stack
int size(struct Stack * S){
    return(S->top +1);
}

//checking if the stack is full or not...if full returns 1 else 0
int isFull(struct Stack * S){
    return(S->top >= S->capacity -1);
}

//double the array size if full
void arrayDouble(struct Stack * S){
    S->capacity *=2;
    S->array = realloc(S->array,S->capacity * sizeof(int));
}

//pushing onto the stack
void push(struct Stack * S, int data){
    //if full double the capacity
    if(isFull(S)){
        arrayDouble(S);
    }
    S->array[++S->top] = data;
}

//pop from the stack
int pop(struct Stack * S){
    if(isEmpty(S))
    {
        printf("\nStack is Empty!");
        return INT_MIN;
    }else{
        return (S->array[S->top--]);
    }
}

//checking the top element in the stack
int peek(struct Stack * S){

    if(isEmpty(S))
    {
        printf("\nStack is empty!");
        return INT_MIN;
    }
    else{
        return S->array[S->top];
    }
}

//printing the stack
void printstack(struct Stack * S){
    int i = S->top;
    printf("\n\nPrinting the stack elements:");
    while(i!=-1)
    {
        printf("\n|| %d ||",S->array[i--]);
    }
}

void deleteStack(struct Stack * S){
    if(S){
        if(S->array)
        {
            free(S->array);
            free(S);
        }
    }
}



int main()
{
    int i=0, capacity = 5;
    struct Stack * stk = createStack(capacity);
    int val;
    //pushing values onto the stack
    for(i=0;i<=capacity;i++){
        printf("\nEnter val: ");
        scanf("%d",&val);
        push(stk,val);
    }

    //printing stack elements
    printstack(stk);

    // top element 
    printf("\n Top element is: %d", peek(stk));

    //printing size of stak
    printf("\nSize of the stack is: %d", size(stk));

    //popping values form stak
    for(i=0;i<=capacity;i++){
        printf("\n Popped item is: %d",pop(stk));
    }

    if(isEmpty(stk))
    {
        printf("\nStack is empty!");
    }else{
        printf("\n Stack is not empty!");
    }

    //Deleting Stack
    deleteStack(stk);
    return 0;
}