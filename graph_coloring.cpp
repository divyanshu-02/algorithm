#include<bits/stdc++.h>
using namespace std;

class graph
{
    int n;
    list<int> *adj;
    int *s;
    int *color;
    public :
    graph(int x)
    {
        n=x;
        adj=new list<int>[n];
        s=new int[n];
        color=new int[n];
        for(int i=0;i<n;i++)
        {
            color[i]=-1;
        }
    }
    void addEdge(int u,int v)
    {
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void mcolor(int m);
    void prints()
    {
        for(int i=0;i<n;i++)
        {
            cout<<color[i]<<" ";
        }
    }
    bool issafe(int n1,int m1)
    {
        list<int> ::iterator i;
        for(i=adj[n1].begin();i!=adj[n1].end();i++)
        {
            if(color[*i]==m1)
            {
                return false;
            }    
        }
        return true;
    }
};
void graph:: mcolor(int m)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(issafe(i,j))
            {
                color[i]=j;
                break;
            }    
        }
    }
}
int main() 
{ 
    graph g1(5); 
    g1.addEdge(0, 1); 
    g1.addEdge(0, 2); 
    g1.addEdge(1, 2); 
    g1.addEdge(1, 3); 
    g1.addEdge(2, 3); 
    g1.addEdge(3, 4); 
    cout << "Coloring of graph 1 \n"; 
    g1.mcolor(3);
    g1.prints();
    return 0;
}    
