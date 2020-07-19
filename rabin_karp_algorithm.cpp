#include<bits/stdc++.h>
using namespace std;
bool istrue(string s1,string s2,int i,int m)
{
    int k=0;
    for(int j=i;j<i+m;j++)
    {
        if(s1[j]!=s2[k])
            return false;
        k++;    
    }
    return true;
}
void check(string s1,string s2,int n,int m)
{
    long long int hash=0,temp=0;
    int i,j;
    for(i=0;i<m;i++)
    {
        hash=hash+s2[i]*pow(52,m-i-1);
    }
    for(i=0;i<m;i++)
    {
        temp=temp+s1[i]*pow(52,m-i-1);
    }
    for(i=0;i<=n-m;i++)
    {
        if(temp==hash)
        {
            if(istrue(s1,s2,i,m)==true)
            {
                cout<<"Pattern found at index - "<<i<<endl;
            }
        }
        temp=temp-s1[i]*pow(52,m-1);
        temp=temp*52;
        temp=temp+s1[i+m];
    }
}
int main()  
{  
    string txt = "GEEKSFORGEEKS";  
    string pat= "GEEK";  
    check(txt, pat,txt.size(),pat.size());
    return 0;  
} 
