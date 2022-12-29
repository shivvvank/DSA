#include<bits/stdc++.h>
using namespace std;
void swap(int &a,int &b)
{
    int c = a;
    a=b;
    b=c;
}
void permuteHelper(vector<vector<int>> &ans,vector<int> nums,int ind)
{
    if(ind==nums.size())
    {
        ans.push_back(nums);
        return;
    }
    vector<int> numstemp(nums);
    for(int i=ind;i<nums.size();i++)
    {
        swap(nums[ind],nums[i]);
        permuteHelper(ans,nums,ind+1);
        nums=numstemp;
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    permuteHelper(ans,nums,0);
    return ans;
} 
int main()
{
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans = permute(nums);
    for(auto i : ans)
    {
        for(auto j : i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    } 
    return 0;
}