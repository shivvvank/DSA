#include<bits/stdc++.h>
using namespace std;
bool print1Subseq(vector<int> &v,vector<int> ans,int sum,int i,int k)
{
    if(i==v.size())
    {
        if(sum==k)
        {
            for(auto i:ans)
                cout<<i<<" ";
            cout<<endl;
            return true;
        }
        return false;
    }

    if(print1Subseq(v,ans,sum,i+1,k))
        return true;
    ans.push_back(v[i]);
    if(print1Subseq(v,ans,sum+v[i],i+1,k))
        return true;
    return false;
}
int main()
{
    vector<int> v={1,2,2,3,4};
    bool ans = print1Subseq(v,{},0,0,4);
    return 0;
}
