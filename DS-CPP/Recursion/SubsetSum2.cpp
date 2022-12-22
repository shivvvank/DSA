#include<bits/stdc++.h>
using namespace std;
void SS2Helper(vector<int> &nums,vector<int> temp,vector<vector<int>> &v,int ind)
{
    v.push_back(temp);
    for(int i=ind;i<nums.size();i++)
    {
        if(i!=ind&&nums[i]==nums[i-1])  continue;
        temp.push_back(nums[i]);
        SS2Helper(nums,temp,v,i+1);
        temp.pop_back();
    }
}
vector<vector<int>> subsetSum2(vector<int> &nums)
{
    vector<vector<int>> v;
    SS2Helper(nums,{},v,0);
    return v; 
}
int main()
{
    vector<int> nums = {1,2,2};
    vector<vector<int>> ans = subsetSum2(nums);
    for(auto i:ans)
    {
        cout<<"[";
                cout<<j<<", ";
        }
        cout<<"]";
    }
    cout<<endl;
    return 0;
}