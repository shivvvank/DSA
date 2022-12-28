#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> a = {1,2,3};
    // vector<int> ans = findAllSubsetSum(a);
    vector<int> ans;
    int n = a.size();
    int count = pow(2,n);
    for(int i=0;i<count;i++)
    {
        int sum =0;
        for(int j = 0;j<n;j++)
        {
            if(i&(1<<j))
            {
                sum+=a[j];
            }
        }
        ans.push_back(sum);
    }
    for(auto i : ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
