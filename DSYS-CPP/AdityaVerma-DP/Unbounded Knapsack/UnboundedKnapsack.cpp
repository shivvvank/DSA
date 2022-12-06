#include<bits/stdc++.h>
using namespace std;
int FindMaxKnapsack(int wt[],int val[],int n,int capacity)
{
    if(n==0)
        return 0;
    if(capacity ==0)
        return 0;
    if(capacity>=wt[n-1])
        return max(val[n-1]+FindMaxKnapsack(wt,val,n,capacity-wt[n-1]),FindMaxKnapsack(wt,val,n-1,capacity));
    else
        return FindMaxKnapsack(wt,val,n-1,capacity);
}
int main()
{
    int wt[]={1,3,4,5};
    int val[]={1,4,5,7};
    int w = 7;
    int n=4;
    int t[n+1][w+1];
    memset(t,-1,sizeof(t));
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            if(i==0||j==0)
                t[i][j]=0;
            if(t[i][j]!=-1)
                continue;
            if(j>=wt[i-1])
            {
                t[i][j]=max(t[i][j-wt[i-1]]+val[i-1],t[i-1][j]);
            }
            else
            {
                t[i][j]=t[i-1][j];
            }
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<t[n][w]<<endl;
    return 0;
}