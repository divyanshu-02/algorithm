#include <bits/stdc++.h> 
using namespace std;
int sfreq(int f[],int i,int j)
{
    int sum=0;
    for(int t=i+1;t<=j;t++)
    {
        sum=sum+f[t];
    }
    return sum;
}
int optimalbin(int k[],int f[],int n)
{
    int c[n][n]={0};
    int s[n][n]={0};
    int i,j,t,w;
    for(int d=1;d<n;d++)
    {
        for(i=0;i<n-d;i++)
        {
            j=i+d;
            w=sfreq(f,i,j);
            int min=9999;
            for(t=i+1;t<=j;t++)
            {
                if(min>c[i][t-1]+c[t][j]+w)
                {
                    min=c[i][t-1]+c[t][j]+w;
                    s[i][j]=t;
                }
            }
            c[i][j]=min;
        }
    }
    return c[0][n-1];
}
int main()  
{  
    int keys[] = {0,10, 12, 20};  
    int freq[] = {0,34, 8, 50};  
    int n = sizeof(keys) / sizeof(keys[0]);  
    cout << "Cost of Optimal BST is " 
         << optimalbin(keys, freq, n);  
    return 0;  
}  
