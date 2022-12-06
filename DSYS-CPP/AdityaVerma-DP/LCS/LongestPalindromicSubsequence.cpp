#include<bits/stdc++.h>
using namespace std;
int main()
{
     string s= "agbcba";
    string t=s;
    reverse(t.begin(),t.end());
    int m = s.length();
    int k[m+1][m+1];
    memset(k,-1,sizeof(k));
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=m;j++)
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
    cout<<"Number of Deletion to make it a palindrome : "<<m-k[m][m]<<endl;
    string ans="";
    int i=m,j=m;
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
                i--;
            else
                j--;
        }
    }
    cout<<ans<<endl;
    return 0;
}