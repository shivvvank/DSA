#include<bits/stdc++.h>
using namespace std;
vector<int> kClosestElements(vector<int> &nums,int x,int k)
{
    priority_queue<pair<int,int>> maxheap;
    vector<int> ans;
    for(int i=0;i<nums.size();i++)
    {
        maxheap.push({abs(x-nums[i]),nums[i]});
        if(maxheap.size()>k)
            maxheap.pop();
    }
    while(maxheap.size()>0)
    {
        ans.push_back(maxheap.top().second);
        maxheap.pop();
    }
    return ans;
}
int main()
{
    vector<int> v = {5,6,7,8,9};
    vector<int> ans = kClosestElements(v,10,3);
    for(auto i:ans)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}