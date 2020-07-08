#include<bits/stdc++.h> 
using namespace std;
int lcs(char a[],char b[],int i,int j)
{
    if(a[i]=='\0'||b[j]=='\0')
    {
        return 0;
    }
    else if(a[i]==b[j])
    {
        return (1+lcs(a,b,i+1,j+1));
    }
    else
    {
        int m=lcs(a,b,i+1,j);
        int n=lcs(a,b,i,j+1);
        if(m>n)
            return m;
        else
            return n;
    }
}
int main() 
{ 
    char X[] = "AGGTAB"; 
    char Y[] = "GXTXAYB"; 
  
    int m = strlen(X); 
    int n = strlen(Y); 
  
    cout<<"Length of LCS is "<<lcs(X, Y, 0, 0); 
    return 0; 
}
