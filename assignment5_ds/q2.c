#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>

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


char *reverseWord(char *input)
{
    int j = 0;
    int len = strlen(input);
    Stack st = newStack(len+1);
    char *ans = (char *)calloc(len + 2, sizeof(char));
    for(int i  = 0;i<len;i++)
    {
        char ch = input[i];
        if(ch==' ')
        {
            while(st->top>-1)
            {
                ans[j++]=peek(st);
                pop(st);
            }
            ans[j++]=' ';
        }
        else
        {
            push(st,ch);
        }

    }
    return ans;
}


int main()
{
    char input[100];
    printf("Enter String \n");
    scanf("%[^\n]s",input);
    // Function call
    input[strlen(input)]=' ';
    char *output = reverseWord(input);
    printf("%s\n", output);
    free(output);
    return 0;
}