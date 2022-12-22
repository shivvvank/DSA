#include<bits/stdc++.h>
using namespace std;
void CSHelper(vector<int> &nums,int target,int ind,vector<int> temp,vector<vector<int>> &v)
{
    if(target==0)
    {
        v.push_back(temp);
        return;
    }
    for(int i=ind;i<nums.size();i++)
    {
        if(i>ind&&nums[i]==nums[i-1]) continue;
        if(nums[i]>target) break;
        temp.push_back(nums[i]);
        CSHelper(nums,target-nums[i],i+1,temp,v);
        temp.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &nums,int target)
{
    vector<vector<int>> v;
    sort(nums.begin(),nums.end());
    CSHelper(nums,target,0,{},v);
    return v;
}
int main()
{
    vector<int> nums={10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> ans = combinationSum2(nums,target);
    for(auto i : ans)
    {
        for(int j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}