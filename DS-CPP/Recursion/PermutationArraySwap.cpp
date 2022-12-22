#include<bits/stdc++.h>
using namespace std;
void permutateHelper(vector<int> &nums,int ind,vector<vector<int>> &v)
{
    if(ind==nums.size())
    {
        v.push_back(nums);
        return;
    }
    for(int i=ind;i<nums.size();i++)
    {
        swap(nums[i],nums[ind]);
        permutateHelper(nums,ind+1,v);
        swap(nums[i],nums[ind]);
    }
}
vector<vector<int>> permutate(vector<int> &nums)
{
    vector<vector<int>> v;
    permutateHelper(nums,0,v);
    return v;
}
int main()
{
    vector<int> nums = {1,2,3};
    vector<vector<int>> v =permutate(nums);
    for(auto i: v)
    {
        for(auto j:i)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}