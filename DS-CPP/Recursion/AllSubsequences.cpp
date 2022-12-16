#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void printAllSubseq(vector<int> &arr,int i,vector<vector<int>> &v,vector<int> pick)
{
    if(i==arr.size())
    {
        v.push_back(pick);
        return;
    }
    printAllSubseq(arr,i+1,v,pick);
    pick.push_back(arr[i]);
    printAllSubseq(arr,i+1,v,pick);
}
int main()
{
    vector<vector<int>> v;
    vector<int> arr = {1,2,3};
    printAllSubseq(arr,0,v,{});
    for(auto i : v)
    {
        for(auto j:i)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
