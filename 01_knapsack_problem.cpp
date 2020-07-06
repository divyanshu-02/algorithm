#include <bits/stdc++.h>

using namespace std;
int knapsack(int p[],int w[],int n,int wt)
{
    int i,j,max;
    int k[n+1][wt+1];
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=wt;j++)
        {
            if(i==0||j==0)
            {
                k[i][j]=0;
            }
            else if(w[i-1]<=wt)
            {
                max=k[i-1][j];
                if(max<(k[i-1][wt-w[i-1]]+p[i-1]))
                {
                    max=(k[i-1][wt-w[i-1]]+p[i-1]);
                }
                k[i][j]=max;
            }
            else
            {
                k[i][j]=k[i-1][j];
            }
        }
    }
    i=n;
    j=wt;
    int pr=0;
    while(i>0&&j>0)
    {
        if(k[i][j]==k[i-1][j])
        {
            i--;;
        }
        else
        {
            pr=pr+p[i-1];
            i--;
            j=j-w[i];
        }
    }
    return pr;
}
int main() 
{ 
    int val[] = { 10,20,30 }; 
    int wt[] = { 1,1,1 }; 
    int W = 2; 
    int n = sizeof(val) / sizeof(val[0]); 
    cout<<knapsack(val,wt,n,W); 
    return 0; 
}
