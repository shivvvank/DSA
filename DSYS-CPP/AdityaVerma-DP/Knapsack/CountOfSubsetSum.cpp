#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[]={1,2,3,4,5};
    int n= sizeof(arr)/sizeof(arr[0]);
    int sum = 9;
    int t[n+1][sum+1];
    memset(t,-1,sizeof(t));
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(i==0)
                t[i][j]=0;
            if(j==0)
                t[i][j]=1;
            if(t[i][j]!=-1)
                continue;
            if(j>=arr[i-1])
            {
                t[i][j]=t[i-1][j-arr[i-1]] + t[i-1][j];
            }
            else
            {
                t[i][j]=t[i-1][j];
            }
        }
    }
    cout<<"Number of possible subsets = "<<t[n][sum]<<endl;
    return 0;
}