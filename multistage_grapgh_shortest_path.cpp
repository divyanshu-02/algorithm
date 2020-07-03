#include<bits/stdc++.h> 
using namespace std;
#define N 8
int shortestdist(int graph[N][N],int s)
{
    int i,j;
    int cost[N]={0};
    int d[N]={0};
    int path[s]={0};
    for(i=N-2;i>=0;i--)
    {
        int min=INT_MAX;
        for(j=i+1;j<N;j++)
        {
            if(graph[i][j]!=0&&graph[i][j]+cost[j]<min)
            {
                min=graph[i][j]+cost[j];
                d[i]=j;
            }
        }
        cost[i]=min;
    }
    for(i=1;i<s;i++)
    {
        path[i]=d[path[i-1]];
    }
    return cost[0];;
}
int main() 
{ 
    // Graph stored in the form of an 
    // adjacency Matrix 
    int graph[N][N] = 
      {{0, 1, 2, 5, 0, 0, 0, 0}, 
       {0, 0, 0, 0, 4, 11, 0, 0}, 
       {0, 0, 0, 0, 9, 5, 16, 0}, 
       {0, 0, 0, 0, 0, 0, 2, 0}, 
       {0, 0, 0, 0, 0, 0, 0, 18}, 
       {0, 0, 0, 0, 0, 0, 0, 13}, 
       {0, 0, 0, 0, 0, 0, 0, 2}}; 
  
    cout << shortestdist(graph,4); 
    return 0; 
}
