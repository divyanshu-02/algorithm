#include<bits/stdc++.h> 
using namespace std;
#define N 4
#define INF 9999
void printg(int graph[N][N],int n)
{
    int i,j,k;
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i==j)
                {
                    graph[i][j]=0;
                }
                if(graph[i][j]>graph[i][k]+graph[k][j])
                {
                    graph[i][j]=graph[i][k]+graph[k][j];
                }
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(graph[i][j] == INF)
                cout<<"INF"<<"--";
            else    
            cout<<graph[i][j]<<"--";
        }
        cout<<endl;
    }
}
int main()  
{  
    /* Let us create the following weighted graph  
            10  
    (0)------->(3)  
        |     /|\  
    5 |     |  
        |     | 1  
    \|/     |  
    (1)------->(2)  
            3     */
    int graph[N][N] = { {0, 5, INF, 10},  
                        {INF, 0, 3, INF},  
                        {INF, INF, 0, 1},  
                        {INF, INF, INF, 0}  
                    };  
  
    // Print the solution  
    printg(graph,4);  
    return 0;  
} 
