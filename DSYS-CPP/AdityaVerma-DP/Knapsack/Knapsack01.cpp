#include<bits/stdc++.h>
using namespace std;
int main()
{
    int wt[]={1,3,4,5};
    int val[]={1,4,5,7};
    int w = 7;
    int n=4;
    int ks[n+1][w+1];
    memset(ks,-1,sizeof(ks));
    int maxx=0;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            if(i==0||j==0)
                ks[i][j]=0;
            if(ks[i][j]!=-1)
                continue;
            if(j>=wt[i-1])
            {
                ks[i][j]=max(ks[i-1][j],ks[i-1][j-wt[i-1]]+val[i-1]);
            }
            else
            {
                ks[i][j]=ks[i-1][j];
            }
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            cout<<ks[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<ks[n][w]<<endl; 
    return 0;
}
