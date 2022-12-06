#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num[] = {1,2,3,4,5,6,7};
    int sum = 16;
    int n=7;
    int ks[n+1][sum+1];
    memset(ks,-1,sizeof(ks));
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(i==0)
                ks[i][j]=0;
            if(j==0)
                ks[i][j]=1;
            if(ks[i][j]!=-1)
                continue;
            if(j>=num[i-1])
            {
                ks[i][j]=ks[i-1][j-num[i-1]] || ks[i-1][j];
            }
            else
            {
                ks[i][j]=ks[i-1][j];
            }
        }
    }
    cout<<ks[n][sum]<<endl;
    return 0;
}