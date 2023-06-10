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
    for(int i = 0;i<n;i++)
    {
        int j = i;
        while(j>0 && compare(str[j-1],str[j])>0)
        {
            char * temp = str[j-1];
            str[j-1]=str[j];
            str[j]=temp;
            j--;
        }
    }

    printf("Sorted order\n");
    for(int i =0;i<n;i++)        
    {
        puts(str[i]);
    }

}