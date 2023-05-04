#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void printOptimal(int k[5][5],int i, int j)
{
    if(i==j)
    {
        printf("A%d",i);
        return;
    }

    printf("(");
    printOptimal(k,i,k[i-1][j-1]);
    printOptimal(k,k[i-1][j-1]+1,j);
    printf(")");
}


void mcm(int d[],int n)
{
    int cost[n][n],k[n][n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cost[i][j] = 0;
            k[i][j] = 0;
        }
    }

    for(int l=2;l<=n;l++)
    {
        for(int i=1;i<=n-l+1;i++)
        {
            int j = i+l-1;

            int min = INT_MAX, k_min = 0;

            for(int m=i;m<j;m++)
            {
                int temp = cost[i-1][m-1] + cost[m][j-1] + (d[i-1]*d[m]*d[j]);

                if(temp<min)
                {
                    min = temp;
                    k_min = m;
                }  
            }
            cost[i-1][j-1] = min;
            k[i-1][j-1] = k_min; 
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ",cost[i][j]);
        }
        printf("\n");        
    }
    
    printf("\nTotal Cost:%d\n",cost[0][n-1]);

    printOptimal(k,1,5);
}


int main()
{
    int n;
    printf("\nEnter Number of Matrix:");
    scanf("%d",&n);
    int d[n+1];
    printf("\nEnter Dimensions of matrix:");
    for(int i=0;i<n+1;i++)
    {
        scanf("%d",&d[i]);
    }

    mcm(d,n);

    return 0;
}