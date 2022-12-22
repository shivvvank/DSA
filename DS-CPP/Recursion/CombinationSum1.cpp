#include<bits/stdc++.h>
using namespace std;
void CSHelper(vector<int> &nums,int target,int ind,vector<int> temp,vector<vector<int>> &v)
{
    if(target<0)
        return;
    if(target==0)
    {
        v.push_back(temp);
        return;
    }
    if(ind==nums.size())
        return;
    CSHelper(nums,target,ind+1,temp,v);
    temp.push_back(nums[ind]);
    CSHelper(nums,target-nums[ind],ind,temp,v);
}
vector<vector<int>> combinationSum(vector<int> &nums,int target)
{
    vector<vector<int>> v;
    CSHelper(nums,target,0,{},v);
    return v;
}
int main()
{
    vector<int> nums={2,3,5};
    int target = 8;
    vector<vector<int>> ans = combinationSum(nums,target);
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