#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void printPath(int p[],int to)
{
    if(p[to]==-1)
    {
        printf("%d",to);
        return;
    }    
    
    printPath(p,p[to]);
    printf("->%d",to);
}

int main()
{
    int v;
    printf("\nEnter number of vertices:");
    scanf("%d",&v);

    int ch = 1;
    int graph[v][v];
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            graph[i][j] = 0;
        }
    }
    
    int parent[v];
    int dist[v];
    int visit[v];
    for (int i = 0; i < v; i++)
    {
        dist[i] = 999;
        parent[i] = -1;
        visit[i] = 0;
    }
    
    while(ch==1)
    {
        printf("\nEnter edge: ");
        int src, dest, weight;
        scanf("%d %d %d",&src,&dest,&weight);
        graph[src][dest] = weight;
        graph[dest][src] = weight;
        printf("\nDo you want to add another edge(yes-1,no-0)");
        scanf("%d",&ch);
    }

    int source;
    printf("\nEnter source node:");
    scanf("%d",&source);

    dist[source]=0;

    for(int i=0;i<v;i++)
    {
        int u,min=INT_MAX;
        //picking the minimum 
        for(int j=0;j<v;j++)
        {
            if(dist[j]<min && !visit[j])
            {
                min = dist[j];
                u = j;
            }
        }

        visit[u] = 1;

        for (int j = 0; j < v; j++)
        {
            if(graph[u][j] && dist[u]+graph[u][j]<dist[j])
            {
                dist[j] = dist[u] + graph[u][j];
                parent[j] = u;
            }
        }
    }
    
    for (int i = 0; i < v; i++)
    {
        printf("\nDistance from %d to %d is %d\n",source,i,dist[i]);
        printPath(parent,i);
    }
    
    return 0;
}