#include<bits/stdc++.h> 
using namespace std; 
typedef  pair<int, int> iPair;
struct Graph 
{ 
    int V, E; 
    vector< pair<int, iPair> > edges; 
  
    Graph(int V, int E) 
    { 
        this->V = V; 
        this->E = E; 
    } 
  
    void addEdge(int u, int v, int w) 
    { 
        edges.push_back({w, {u, v}}); 
    } 
  
    int kruskalMST(); 
};
struct DisjointSets
{
    int *rank;
    int *parent;
    int n;
    DisjointSets(int n)
    {
        this->n=n;
        rank=new int[n];
        parent=new int[n];
        for(int i=0;i<n;i++)
        {
            rank[i]=0;
            parent[i]=i;
        }
    }
    int find(int i)
    {
        if(parent[i]==i)
        {
            return i;
        }
        else
        {
            return(find(parent[i]));
        }
    }
    void merge(int u,int v)
    {
        int urep=find(u);
        int vrep=find(v);
        if(rank[urep]>rank[vrep])
        {
            parent[vrep]=urep;
            rank[urep]++;
        }
        else
        {
            parent[urep]=vrep;
            rank[vrep]++;
        }
    }
    
};
int Graph :: kruskalMST()
{
    int wt=0;
    sort(edges.begin(),edges.end());
    DisjointSets ds(V);
    vector<pair<int,iPair>>::iterator it;
    for(it=edges.begin();it!=edges.end();it++)
    {
        int u=it->second.first;
        int v=it->second.second;
        
        int pu=ds.find(u);
        int pv=ds.find(v);
        if(pu!=pv)
        {
            cout << u << " - " << v << endl;
            wt=wt+it->first;
            ds.merge(pu,pv);
        }
    }
    return wt;
}
int main() 
{ 
   
    int V = 9, E = 14; 
    Graph g(V, E); 
  
    
    g.addEdge(0, 1, 4); 
    g.addEdge(0, 7, 8); 
    g.addEdge(1, 2, 8); 
    g.addEdge(1, 7, 11); 
    g.addEdge(2, 3, 7); 
    g.addEdge(2, 8, 2); 
    g.addEdge(2, 5, 4); 
    g.addEdge(3, 4, 9); 
    g.addEdge(3, 5, 14); 
    g.addEdge(4, 5, 10); 
    g.addEdge(5, 6, 2); 
    g.addEdge(6, 7, 1); 
    g.addEdge(6, 8, 6); 
    g.addEdge(7, 8, 7); 
  
    cout << "Edges of MST are \n"; 
    int mst_wt = g.kruskalMST(); 
  
    cout << "\nWeight of MST is " << mst_wt; 
  
    return 0; 
}
