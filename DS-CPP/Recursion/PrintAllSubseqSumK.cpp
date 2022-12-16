#include<bits/stdc++.h>
using namespace std;
void printSubseqSumK(vector<int> &v,vector<int> ans,int sum,int i,int k)
{
    if(i==v.size())
    {
        if(sum==k)
        {
            for(auto i:ans)
                cout<<i<<" ";
            cout<<endl;
        }
        return;
    }
    printSubseqSumK(v,ans,sum,i+1,k);
    ans.push_back(v[i]);
    printSubseqSumK(v,ans,sum+v[i],i+1,k);
}
int main()
{
    vector<int> v = {1,2,2,3,4};
    printSubseqSumK(v,{},0,0,4);
    return 0;
}