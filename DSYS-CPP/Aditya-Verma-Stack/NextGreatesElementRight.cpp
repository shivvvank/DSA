#include<bits/stdc++.h>
using namespace std;
vector<int> findNGER(vector<int> nums)
{  
    stack<int> s;
    vector<int> ans ;
    for(int i=nums.size()-1;i>=0;i--)
    {
        while(s.size()>0&&nums[i]>s.top())
            s.pop();
        if(s.size()==0)
            ans.push_back(-1);
        else
            ans.push_back(s.top());
        s.push(nums[i]);
    }
    return ans;
}
int main()
{
    vector<int> nums={1,3,2,4};
    vector<int> ans = findNGER(nums);
    for(auto i: ans)
        cout<<i<<" ";
    cout<<endl;  
    return 0;
}