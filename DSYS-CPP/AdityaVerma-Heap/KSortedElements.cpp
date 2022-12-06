#include<bits/stdc++.h>
using namespace std;
void sortKsorted(vector<int> &v,int k)
{
    priority_queue<int,vector<int>,greater<int>> minheap;
    int j = 0;
    for(int i = 0;i<v.size();i++)
    {
        minheap.push(v[i]);
        if(minheap.size()>k)
        {
            v[j]=minheap.top();
            j++;
            minheap.pop();
        }
    }
    cout<<minheap.size()<<endl;
    while(j<v.size())
    {
        v[j++]=minheap.top();
        minheap.pop();
    }
}
int main()
{
    vector<int> v ={6,5,3,2,8,10,9};
    int k = 3;
    sortKsorted(v,3);
    for(auto i:v)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}
