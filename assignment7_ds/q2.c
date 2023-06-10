#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int compare(char *s1,char*s2)
{
    return strcmp(s1,s2);
}

int main()
{
    int n;
    scanf("%d",&n);

    char ** str = (char**)calloc(n,sizeof(char*));
    for(int i =0;i<n;i++)
    {
        str[i] = (char*)calloc(1,sizeof(char*));
    }
        
    fflush(stdin);

    for(int i =0;i<n;i++)
    {
        scanf("%[^\n]s",str[i]);
        fflush(stdin);
    }

    printf("Enter word to search\n");
    char *input = (char*)calloc(1,sizeof(char*));
    scanf("%[^\n]s",input);


    int index = 0;
    for(int i = 0;i<n;i++)
    {
        if(strcmp(str[i],input)==0)
        {
            index = i;
            break;
        }
    }

    printf("Found at index %d",index);

    
    

}