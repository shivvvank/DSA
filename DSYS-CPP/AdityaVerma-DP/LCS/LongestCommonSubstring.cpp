#include<bits/stdc++.h>
using namespace std;
int LongestCommonSubstring(string s,string t,int m,int n,int & maxx)
{
    if(n==0||m==0)
        return 0;
    if(s.at(m-1)==t.at(n-1))
    {
        int temp = 1+LongestCommonSubstring(s,t,m-1,n-1,maxx);
        if(maxx<temp)
        {
            cout<<maxx<<endl;
            maxx=temp;
        }
        return temp;
    }
    else
        return 0;
}
int main()
{
    string a = "abcdef";
    string b = "cdefgh";
    int m=a.length();
    int n=b.length();
    int maxx =-1;
    int temp = LongestCommonSubstring(a,b,m,n,maxx);
    cout<<maxx<<endl;
    return 0;
}