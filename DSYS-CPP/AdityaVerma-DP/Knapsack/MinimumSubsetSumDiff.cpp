#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[]={-36,36};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 0;
    for(int i=0;i<n;i++)
        sum+=arr[i];
    int t[n+1][sum+1];
    memset(t,-1,sizeof(t));
    int minsd=INT_MAX;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(i==0)
                t[i][j]=0;
            if(j==0)
            {
                t[i][j]=1;
                minsd=min(minsd,abs(sum-(2*j)));
            }
            if(t[i][j]!=-1)
                continue;
            if(j>=arr[i-1])
            {
                t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
                if(t[i][j]==1)
                    minsd=min(minsd,abs(sum-(2*j)));
            }
            else
            {
                t[i][j]=t[i-1][j];
                if(t[i][j]==1)
                    minsd=min(minsd,abs(sum-(2*j)));
            }
        }
    }
    cout<<minsd<<endl;
    return 0;
}