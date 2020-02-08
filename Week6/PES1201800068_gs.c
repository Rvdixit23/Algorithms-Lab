#include <stdbool.h>
#include <stdlib.h>
#include "graphSearch.h"

void dfs(int v, int n, int* visited, int parent, int* houses,const int graph[][n], int k)
{
    visited[v]++;
    (*houses)++;
    for(int i=0;i<n;i++)
    {
        if(abs(v-i)<=k)
        {
            if(graph[v][i] && visited[i] && i!=parent)
                ++visited[i];
            if(!visited[i] && graph[v][i])
                dfs(i,n,visited,v,houses,graph,k);
        }
    }
}

bool isTree(int n, const int graph[][n])
{
    int* visited=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
        visited[i]=0;
    int h=0;
    dfs(0,n,visited,0,&h,graph,n);
    for(int i=0;i<n;i++)
        if(visited[i]!=1)
            return false;
    return true;
}

Result pepesAnswers(int n, const int safeSeq[][n])
{
    return pepesAnswersWithK(n,safeSeq,n);
}

Result pepesAnswersWithK(int n, const int safeSeq[][n], int k)
{
    Result r;
    r.maxHouses=0;
    r.numDeliveryFrogs=0;
    int h=0;
    int* visited=(int*)calloc(n,sizeof(int));
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            h=0;
            dfs(i,n,visited,i,&h,safeSeq,k);
            r.numDeliveryFrogs++;
        }
        if(h>r.maxHouses)
            r.maxHouses=h;
    }
    return r;
}