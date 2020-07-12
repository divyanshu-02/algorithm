#include<bits/stdc++.h>
using namespace std;
bool issafe(int i,int graph[5][5],int x[],int k)
{
    if(graph[x[k-1]][i]==0)
        return false;
    for(int j=0;j<k;j++)
    {
        if(x[j]==i)
            return false;
    }
    return true;    
}
bool graphtill(int graph[5][5],int x[],int k,int n)
{
    if(k==n)
    {
        if(graph[x[k-1]][0]==1)
            return true;
        else 
            return false;
    }
    for(int i=1;i<n;i++)
    {
        if(issafe(i,graph,x,k))
        {
            x[k]=i;
            if(graphtill(graph,x,k+1,n)==true)
                return true;
            x[k]=-1;    
        }
    }
    return false;
}
void hamcycle(int graph[5][5],int n)
{
    int x[n]={-1};
    x[0]=0;
    if(graphtill(graph,x,1,n)==false)
    {
        cout<<"\nsolution does not exist"<<endl;
    }
    for(int i=0;i<n;i++)
    {
       cout<<x[i]<<" ";
    }
}
int main()  
{  
    /* Let us create the following graph  
        (0)--(1)--(2)  
        | / \ |  
        | / \ |  
        | / \ |  
        (3)-------(4) */
    int graph1[5][5] = {{0, 1, 0, 1, 0},  
                        {1, 0, 1, 1, 1},  
                        {0, 1, 0, 0, 1},  
                        {1, 1, 0, 0, 1},  
                        {0, 1, 1, 1, 0}};  
      
    // Print the solution  
    hamcycle(graph1,5); 
    return 0;
}    
