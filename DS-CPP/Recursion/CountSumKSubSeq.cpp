#include<bits/stdc++.h>
using namespace std;
int countSumKSubseq(vector<int> &v,int sum,int i , int k)
{
    if(i==v.size())
    {
        if(sum==k)
            return 1;
        return 0;
    }
    int t1 = countSumKSubseq(v,sum,i+1,k);
    int t2 = countSumKSubseq(v,sum+v[i],i+1,k);
    return t1+t2;
}
int main()
{
    vector<int> v = {1,2,2,3,4};
    cout<<countSumKSubseq(v,0,0,4)<<endl;
    return 0;
}
