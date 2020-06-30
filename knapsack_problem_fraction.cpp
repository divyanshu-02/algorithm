#include <iostream> 
using namespace std; 
int main()
{
    int n;
    cout<<"Enter the number of items : ";
    cin>>n;
    int i,p[n],w[n],wt,r,k;
    float d[n],pt=0;
    cout<<"Enter weight and profit of items : \n";
    for(i=0;i<n;i++)
    {
        cin>>w[i]>>p[i];
        d[i]=p[i]/w[i];
    }
    cout<<"Enter the maximum weight : ";
    cin>>wt;
    r=0;
    while(r<=wt)
    {
        int max=0;
        for(i=0;i<n;i++)
        {
            if(d[i]>=max)
            {
                max=d[i];
                k=i;
            }
        }
        if((wt-r)>w[k])
        {
            pt=pt+p[k];
            r=r+w[k];
        }
        else
        {
            pt=pt+(wt-r)*d[k];
            break;
        }
        d[k]=0;
        
    }
    cout<<"The maximum profit is : "<<pt;
    return 0;
}
