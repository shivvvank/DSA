#include<bits/stdc++.h>
using namespace std;
void SSHelper(vector<int> &nums,int ind,int sum,set<int> &sums)
{
    if(ind==nums.size())
    {
        sums.insert(sum);
        return;
    }
    SSHelper(nums,ind+1,sum,sums);
    SSHelper(nums,ind+1,sum+nums[ind],sums);
}
vector<int> subsetSum(vector<int> &nums)
{
    set<int> sums;
    vector<int> ans;
    SSHelper(nums,0,0,sums);
    for(auto i:sums)
    {
        ans.push_back(i);
    }
    return ans;
}
int main()
{
    vector<int> nums ={2,3};
    vector<int> ans = subsetSum(nums);
    for(auto i: ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
