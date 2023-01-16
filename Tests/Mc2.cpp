#include<bits/stdc++.h>
using namespace std;
int returnans(string s)
{
    int tot_x = 0;
    int tot_y = 0;
    int ans=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='x')
            tot_x++;
        if(s[i]=='y')
            tot_y++;
    }
    if(tot_x==tot_y&&tot_y==0)
        return s.length()-1;
    int cur_x=0,cur_y=0,nxt_x=tot_x,nxt_y=tot_y;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='x')
        {
            cur_x++;
            nxt_x--;
        }
        if(s[i]=='y')
        {
            cur_y++;
            nxt_y--;
        }
        if(cur_x==cur_y||nxt_x==nxt_y)
        {
            ans++;
        }
    }
    return ans-1;
}
int main()
{
    string s = "ayxbx";
    cout<<returnans(s)<<endl;
    return 0;
}
