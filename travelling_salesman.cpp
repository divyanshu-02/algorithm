#include<bits/stdc++.h> 
using namespace std;
int travels(int graph[4][4],int s)
{
    int i,j=0,k;
    vector<int> vertex;
    for(i=0;i<4;i++)
    {
        if(i!=k)
        {
            vertex.push_back(i);
        }
    }
    int min=9999;
    do
    {
        int cpath=0;
        int k=s;
        for(i=0;i<vertex.size();i++)
        {
            cpath=cpath+graph[k][vertex[i]];
            k=vertex[i];
        }
        cpath=cpath+graph[k][s];
        if(min>cpath)
        {
            min=cpath;
        }
    }while(next_permutation(vertex.begin(),vertex.end()));
    return min;
}
int main() 
{ 
    // matrix representation of graph 
    int graph[][4] = { { 0, 10, 15, 20 }, 
                       { 10, 0, 35, 25 }, 
                       { 15, 35, 0, 30 }, 
                       { 20, 25, 30, 0 } }; 
    int s = 0; 
    cout << travels(graph, s) << endl; 
    return 0; 
}
