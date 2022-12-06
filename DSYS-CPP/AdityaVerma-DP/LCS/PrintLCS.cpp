#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s = "hattbc";
    string t= "attilele";
    int m = s.length();
    int n = t.length();
    int tt[m+1][n+1];
    memset(tt,-1,sizeof(tt));
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0||j==0)
                tt[i][j]=0;
            if(tt[i][j]!=-1)
                continue;
            if(s.at(i-1)==t.at(j-1))
                tt[i][j]=1+tt[i-1][j-1];
            else
                tt[i][j]=max(tt[i-1][j],tt[i][j-1]);
        }
    }   
    string ans ="";
    int i=m,j=n;
    while(i!=0&&j!=0)
    {
        if(s.at(i-1)==t.at(j-1))
        {
            ans=ans+s.at(i-1);
            i--;
            j--;
        }
        else
        {
            if(tt[i-1][j]>tt[i][j-1])
                i--;
            else
                j--;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
    return 0;
}