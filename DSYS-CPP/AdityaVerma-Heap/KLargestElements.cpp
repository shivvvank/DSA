#include<bits/stdc++.h>
using namespace std;
vector<int> klargestElements(vector<int> &v,int k)
{
    priority_queue<int,vector<int>,greater<int>> minHeap;
    for(int i=0;i<v.size();i++)
    {
        minHeap.push(v[i]);
        if(minHeap.size()>k)
            minHeap.pop();
    }
    vector<int> ans;
    while(minHeap.size()>0)
    {
        ans.push_back(minHeap.top());
        minHeap.pop();
    }
    return ans;
}
int main()
{
    vector<int> v = {1,4,3,7,15,10};
    vector<int> ans = klargestElements(v,3);
    for(auto i:ans)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}