#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
    int top;
    unsigned capacity;
    char *arr;
} Stack_t, *Stack;

Stack newStack(unsigned capacity)
{
    Stack st = (Stack)calloc(1, sizeof(Stack_t));
    st->top = -1;
    st->capacity = capacity;
    st->arr = (char *)calloc(capacity, sizeof(char));

    return st;
}

void push(Stack st, char data)
{
    if (st->top + 1 == st->capacity)
    {
        return;
    }
    else
    {
        st->top++;
        st->arr[st->top] = data;
    }
}

char pop(Stack st)
{
    // printf("%d\n",st->top);
    if (st->top == -1)
    {
        return -1;
    }
    else
    {
        char ele = st->arr[st->top];
        st->top--;
        return ele;
    }
}

char peek(Stack st)
{
    if (st->top == -1)
    {
        return -1;
    }
    else
    {
        return st->arr[st->top];
    }
}

void printStack(Stack st)
{
    for (int i = 0; i <= st->top; i++)
    {
        printf("%c ", st->arr[i]);
    }
    printf("\n");
}

void balanced(char * str)
{
    Stack st = newStack(strlen(str)+2);
    for(int i = 0;i<strlen(str);i++)
    {
        char ch = str[i];
        // printf("%c ",ch);
        if(ch=='(' || ch=='{' || ch=='[')
        {
            push(st,ch);
        }
        else if(ch==']' || ch=='}' || ch==')')
        {
            if(ch==')' && peek(st)=='(' || ch=='}' && peek(st)=='{' || ch==']' && peek(st)=='[')
            {
                pop(st);
            }
            else
            {
                printf("Invalid");
                return ;
            }
        }
    
    }

    if(st->top==-1)
    {
        printf("Valid");
    }
    else
    {
        printf("Invalid");
    }
}


int main()
{
    char infix[100] ;
    printf("Enter String \n");
    scanf("%s",infix);
    balanced(infix);
}
