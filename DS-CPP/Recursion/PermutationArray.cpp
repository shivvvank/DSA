#include<bits/stdc++.h>
using namespace std;
void permutateHelper(vector<int> &nums,vector<int> temp,vector<bool> flag,vector<vector<int>> &v)
{
    if(temp.size()==nums.size())
    {
        v.push_back(temp);
        return;
    }
    for(int i=0;i<nums.size();i++)
    {
        if(flag[i]) continue;
        temp.push_back(nums[i]);
        flag[i]=true;
        permutateHelper(nums,temp,flag,v);
        temp.pop_back();
        flag[i]=false;
    }
}
vector<vector<int>> permutate(vector<int> &nums)
{
    vector<vector<int>> v ;
    vector<bool> flag(nums.size(),false);
    permutateHelper(nums,{},flag,v);
    return v;
}
int main()
{
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans = permutate(nums);
    for(auto i : ans)
    {
        for(int j:i)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}