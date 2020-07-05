#include <bits/stdc++.h>

using namespace std;
int matrixmul(int p[],int n)
{
    int m[n][n]={0};
    int s[n][n]={0};
    int i,j,k,d;
    for(d=1;d<n;d++)
    {
        for(i=0;i<n-d;i++)
        {
            j=i+d;
            int min=99999;
            for(k=i;k<j;k++)
            {
                if(min>(m[i][k]+m[k+1][j]+(p[i]*p[k+1]*p[j+1])))
                {
                    min=(m[i][k]+m[k+1][j]+(p[i]*p[k+1]*p[j+1]));
                    s[i][j]=k+1;
                }
            }
            m[i][j]=min;
        }
    }
    return m[0][n-1];
}
