#include<bits/stdc++.h>
using namespace std;
int main()
{
    int c[] = {1,2,3};
    int note = 5;
    int n = sizeof(c)/sizeof(c[0]);
    int w = note;
    int t[n+1][w+1];
    memset(t,-1,sizeof(t));
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            if(i==0)
                t[i][j]=0;
            if(j==0)
                t[i][j]=1;
            if(t[i][j]!=-1)
                continue;
            if(j>=c[i-1])
                t[i][j]=t[i][j-c[i-1]] + t[i-1][j];
            else
                t[i][j]=t[i-1][j];
        }
    }
    cout<<"Number of Ways : "<<t[n][w]<<endl;
    int minCoins=0;
    for(int i=0;i<=n;i++)
    {
        if(t[i][w]>0)
        {
            minCoins=i;
            break;
        }
    }
    cout<<"Number of Coins : "<<minCoins<<endl;
    return 0;
}