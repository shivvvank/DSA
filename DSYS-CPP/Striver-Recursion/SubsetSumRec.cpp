#include<bits/stdc++.h>
using namespace std;
void SSHelper(vector<int> &ans,vector<int> &a,int sum,int i)
{
    if(i==a.size())
    {
        ans.push_back(sum);
        return;
    }
    SSHelper(ans,a,sum,i+1);
    SSHelper(ans,a,sum+a[i],i+1);
}
vector<int> findAllSubsetSum(vector<int> &a)
{
    vector<int> ans ;
    SSHelper(ans,a,0,0);
    return ans;
}
int main()
{
    vector<int> a={3,1,2};
    vector<int> ans=findAllSubsetSum(a);
    for(auto i: ans)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}