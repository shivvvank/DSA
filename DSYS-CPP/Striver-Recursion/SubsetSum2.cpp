#include<bits/stdc++.h>
using namespace std;
void SSHelper(vector<vector<int>> &ans,vector<int> &a,vector<int> temp,int i)
{
    if(i==a.size())
    {
        ans.push_back(temp);
        return ;
    }
    int lastind=i+1;
    while(lastind<a.size()&&a[lastind-1]==a[lastind])
        lastind++;
    temp.push_back(a[i]);
    SSHelper(ans,a,temp,i+1);
    temp.pop_back();
    SSHelper(ans,a,temp,lastind);
}
vector<vector<int>> findAllSubset(vector<int> &a)
{
    vector<vector<int>> ans ;
    SSHelper(ans,a,{},0);
    return ans;
}
int main()
{
    vector<int> a={1,2,2};
    sort(a.begin(),a.end()); 
    vector<vector<int>> ans=findAllSubset(a);
    for(auto i: ans)
    {
        for(auto j : i)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}