#include<stdlib.h>
#include"tsp.h"

int getCost(int n, int graph[][n], int *P)
{
    int cost = 0;
    for (int i = 1; i < n; i++)
    {
        cost += graph[P[i - 1]][P[i]];
    }
    cost += graph[P[n - 1]][P[0]];
    return cost;
}

int tsp(int n, int graph[][n])
{
    int *perm = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        perm[i] = i;
    }
    int minCost = getCost(n, graph, perm);
    int tempCost;
    while (get_next_permutation(perm, n))
    {
        tempCost = getCost(n, graph, perm);
        if (tempCost < minCost)
        {
            minCost = tempCost;
        }
    }

    return minCost;
}

int *printPath(int n, int graph[][n])
{
    int *perm = (int *)malloc(sizeof(int) * n);
    int *solution = (int *)malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++)
    {
        perm[i] = i;
    }
    int minCost = getCost(n, graph, perm);
    int tempCost;
    for (int i = 0; i < n; i++)
    {
        solution[i] = perm[i];
    }
    while (get_next_permutation(perm, n))
    {
        tempCost = getCost(n, graph, perm);
        if (tempCost < minCost)
        {
            for (int i = 0; i < n; i++)
            {
                solution[i] = perm[i];
            }
            minCost = tempCost;
        }
    }
    return solution;
}