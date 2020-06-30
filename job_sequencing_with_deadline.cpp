#include <bits/stdc++.h>

using namespace std;
struct job
{
    char id;
    int deadline;
    int profit;
};
void merge(job j[],int l,int mid,int h)
{
    int i,m,k,n1,n2;
    n1=mid-l+1;
    n2=h-mid;
    job j1[n1],j2[n2];
    for(i=0;i<n1;i++)
    {
        j1[i]=j[l+i];
    }
    for(m=0;m<n2;m++)
    {
        j2[m]=j[mid+1+m];
    }
    i=0;
    m=0;
    k=l;
    while(i<n1&m<n2)
    {
        if(j1[i].profit>j2[m].profit)
        {
            j[k]=j1[i];
            i++;
            k++;
        }
        else
        {
            j[k]=j2[m];
            m++;
            k++;
        }
    }
    while(i<n1)
    {
        j[k]=j1[i];
        i++;
        k++;
    }
    while(m<n2)
    {
        j[k]=j2[m];
        m++;
        k++;
    }
}
void mergesort(job j[],int l,int h)
{
    if(l<h)
    {
        int mid=(l+h)/2;
        mergesort(j,l,mid);
        mergesort(j,mid+1,h);
        merge(j,l,mid,h);
    }
}
int main()
{
  int n;
  int i,t,k;
  cout<<"Enter the number of jobs : ";
  cin>>n;
  job j[n];
  cout<<"Enter the max deadline : ";
  cin>>t;
  int d[t];
  for(i=0;i<t;i++)
  {
      d[i]=-1;
  }
  cout<<"Enter the id , deadline and profitr of jobs :\n";
  for(i=0;i<n;i++)
  {
      cin>>j[i].id>>j[i].deadline>>j[i].profit;
  }
  mergesort(j,0,n-1);
  for(i=0;i<n;i++)
  {
      k=j[i].deadline;
      if(d[k-1]==-1)
      {
          d[k-1]=i;
      }
      else
      {
          do
          {
              k--;
          }while(d[k-1]!=-1&&k>0);
          if(k!=0)
          {
              d[k-1]=i;
          }
      }
  }
  cout<<"Sequence is : \n";
  for(i=0;i<t;i++)
  {
      cout<<j[d[i]].id<<";";
  }
  return 0;
}
