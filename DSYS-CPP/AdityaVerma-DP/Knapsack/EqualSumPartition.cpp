#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {1,5,6,12};
    int n=4;
    int sum =0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    if(sum%2!=0)
    {
        cout<<"Not possible"<<endl;
        return 0;
    }
    sum=sum/2;
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
            if(j>=arr[i-1])
            {
                ks[i][j] = ks[i-1][j-arr[i-1]] || ks[i-1][j];
            }
            else
            {
                ks[i][j]= ks[i-1][j];
            }
        }
    }
    if(ks[n][sum]==1)
    {
        cout<<"Possible"<<endl;
    }
    else
    {
        cout<<"Not possible"<<endl;
    }
    return 0;
}