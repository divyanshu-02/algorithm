#include <bits/stdc++.h> 
using namespace std;
class graph
{
    int n;
    list<int> *adj;
    void APUtil(int v, bool visited[], int disc[], int low[],  
                int parent[], bool ap[]); 
    public :
    graph(int x)
    {
        n=x;
        adj=new list<int>[n];
    }
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }
    void AP(); 
    
};
void graph:: AP()
{
    bool visited[n];
    int disc[n];
    int low[n];
    int parent[n];
    bool ap[n];
    for(int i=0;i<n;i++)
    {
        parent[i]=-1;
        visited[i]=false;
        ap[i]=false;
    }
    for(int i=0;i<n;i++)
    {
        APUtil(i,visited,disc,low,parent,ap);
    }
    for(int i=0;i<n;i++)
    {
        if(ap[i]==true)
        {
            cout<<i<<endl;
        }
    }
}
void graph:: APUtil(int u, bool visited[], int disc[], int low[],int parent[], bool ap[])
{
    static int time=0;
    int children=0;
    visited[u]=true;
    disc[u]=++time;
    low[u]=time;
    list<int>::iterator i;
    for(i=adj[u].begin();i!=adj[u].end();i++)
    {
        int v=*i;
        if(!visited[v])
        {
            children++;
            parent[v]=u;
            APUtil(v,visited,disc,low,parent,ap);
            if(low[u]>low[v])
            {
                low[u]=low[v];
            }
            if(parent[u]==-1&&children>1)
            {
                ap[u]=true;
            }
            if(parent[u]!=-1&&low[v]>=disc[u])
            {
                ap[u]=true;
            }
        }
        else if(v!=parent[u])
        {
            if(low[u]>disc[v])
            {
                low[u]=disc[v];
            }
        }
    }
}
int main() 
{ 
    // Create graphs given in above diagrams 
    cout << "\nArticulation points in first graph \n"; 
    graph g1(5); 
    g1.addEdge(1, 0); 
    g1.addEdge(0, 2); 
    g1.addEdge(2, 1); 
    g1.addEdge(0, 3); 
    g1.addEdge(3, 4); 
    g1.AP();
    return 0;
}    
