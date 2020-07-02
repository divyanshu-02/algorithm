#include<bits/stdc++.h> 
using namespace std;
int mindistance(int dist[],bool sptset[],int n)
{
    int mindist=INT_MAX;
    int j;
    for(int i=0;i<n;i++)
    {
        if(dist[i]<=mindist&&sptset[i]==false)
        {
            mindist=dist[i];
            j=i;
        }
    }
    return j;
}
void prints(int dist[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<i<<"---"<<dist[i]<<endl;
    }
}
void dijkstra(int graph[9][9],int src,int n)
{
    bool sptset[n];
    int dist[n];
    for(int i=0;i<n;i++)
    {
        dist[i]=INT_MAX;
        sptset[i]=false;
    }
    dist[src]=0;
    for(int j=0;j<n;j++)
    {
        int u=mindistance(dist,sptset,n);
        sptset[u]=true;
        for(int i=0;i<n;i++)
        {
            if(sptset[i]==false&&graph[u][i]&&dist[u]!=INT_MAX&&dist[u]+graph[u][i]<dist[i])
            {
                dist[i]=dist[u]+graph[u][i];
            }
        }
    }
    prints(dist,n);
}
int main()
{
    int n=9;
    int graph[9][9] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
  
    dijkstra(graph,0,n); 
  
    return 0;
}
