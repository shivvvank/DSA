#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s= "heap";
    string t= "pea";
    int m = s.length();
    int n =t.length();
    int k[m+1][n+1];
    memset(k,-1,sizeof(k));
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0||j==0)
                k[i][j]=0;
            if(k[i][j]!=-1)
                continue;
            if(s.at(i-1)==t.at(j-1))
                k[i][j]=1+k[i-1][j-1];
            else
                k[i][j]=max(k[i-1][j],k[i][j-1]);
        }
    }
    cout<<"Number of Deletion : "<<n-k[m][n]<<endl;
    cout<<"Number of Insertion : "<<m-k[m][n]<<endl;
    return 0;
}