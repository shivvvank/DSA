#include<bits/stdc++.h>
using namespace std;
// int LCS(string s,string t,int m ,int n)
// {
//     if(n==0||m==0)
//         return 0;
//     if(s.at(m-1)==t.at(n-1))
//         return 1+LCS(s,t,m-1,n-1);
//     else
//         return max(LCS(s,t,m-1,n),LCS(s,t,m,n-1));
// }
int main()
{
    string s="abcdefgh";
    string t="abcdfe";
    int m = s.length();
    int n= t.length();
    int l[m+1][n+1];
    memset(l,-1,sizeof(l));
    int maxlcs=0;
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0||j==0)
                l[i][j]=0;
            if(l[i][j]!=-1)
                continue;
            if(s.at(i-1)==t.at(j-1))
            {
                l[i][j]=1+l[i-1][j-1];
            }
            if(s.at(i-1)!=t.at(j-1))
                l[i][j]=max(l[i][j-1],l[i-1][j]);
        }
    }
    cout<<l[m][n]<<endl;
    return 0;
}