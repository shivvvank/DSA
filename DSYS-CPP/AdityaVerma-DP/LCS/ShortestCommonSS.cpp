#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s= "AGGTAB";
    string t= "GXTXYAYB";
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
    int i=m,j=n;
    string ans="";
    while(i!=0&&j!=0)
    {
        if(s.at(i-1)==t.at(j-1))
        {
            ans+=s.at(i-1);
            i--;
            j--;
        }
        else
        {
            if(k[i-1][j]>k[i][j-1])
            {
                ans+=s.at(i-1);
                i--;
            }
            else
            {
                ans+=t.at(j-1);
                j--;
            }
        }
    }
    cout<<"Length of SCS : "<<m+n-k[m][n]<<endl;
    while(i!=0)
    {
        ans+=s.at(i-1);
        i--;
    }
    while(j!=0)
    {
        ans+=t.at(j-1);
        j--;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
    return 0;
}