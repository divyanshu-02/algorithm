#include<bits/stdc++.h>
using namespace std;
void computelps(string s,int lps[],int m)
{
    int len=0;
    int i=0;
    lps[0]=0;
    i=1;
    while(i<m)
    {
        if(s[len]==s[i])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len!=0)
            {
                len=lps[len-1];
            }
            else
            {
                lps[i]=0;
                len++;
            }
        }
    }
}
int check(string s1,string s2,int n,int m)
{
    int i=0,j=0,index=0;
    int lps[m];
    computelps(s2,lps,m);
    while(i<n)
    {
        
        if(s1[i]==s2[j])
        {
            i++;
            j++;
            if(j==m)
            {
                return (i-j);
            }
        }
        else
        {
            if(j==0)
            {
                i++;
            }
            else
            {
                j=lps[j];
            }
        }
    }
    return -1;
}
int main() 
{ 
    string txt = "ABABDABACDABABCABAB"; 
    string pat= "ABABCABAB"; 
    cout<<check(txt, pat,txt.size(),pat.size()); 
    return 0; 
}
