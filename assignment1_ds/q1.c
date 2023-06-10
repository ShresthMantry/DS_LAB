#include<stdio.h>
#include<stdlib.h>

int **createMatrix (int m,int n)
{
    int **ans = (int **)calloc(m,sizeof(int*));
    for(int i =0;i<m;i++)
    {
        ans[i]=(int*) calloc (n,sizeof(int));
    }

    return ans;
}

void initialize_matrix(int **matrix,int m,int n)
{
    for(int i =0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
}

int main(){
    int m,n;
    printf("enter m and n \n");
    scanf("%d",&m);
    scanf("%d",&n);

    int **matrix = createMatrix(m,n);
    printf("Enter matrix \n");
    initialize_matrix(matrix,m,n);

    printf("Original Matrix \n");
    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }


    int sum = 0;
    for(int i = 0;i<n;i++)
    {
        sum = sum+matrix[0][i];
    }

    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            matrix[i][j]=sum*matrix[i][j];
        }
    }

    printf("New Matrix \n");
    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }


}