#include<bits/stdc++.h>
using namespace std;

/* 

bool letscheck(vector<int> &nums,int ind,vector<bool> dp)
{
    if(ind==nums.size()-1)
        return dp[ind]=true;
    for(int i=1;i<=nums[ind];i++)
    {
        if(dp[ind+i])
            return dp[ind]=true;
    }
    return dp[ind]=false;
}
bool canJump(vector<int>& nums) {
    vector<bool> dp(nums.size(),false);
    letscheck(nums,0,dp);
    return dp[0];
}

*/

int main()
{
    vector<int> a = {1,2,3,4,5};
    vector<vector<int>> suba;
    for(int i=0;i<a.size();i++)
    {
        for(int j=i+1;j<=a.size();j++)
        {
            vector<int> temp;
            for(int k = i;k<j;k++)
            {
                temp.push_back(a[k]);
            }
            suba.push_back(temp);
        }
    }
    for(auto i : suba)
    {
        for(auto j : i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
