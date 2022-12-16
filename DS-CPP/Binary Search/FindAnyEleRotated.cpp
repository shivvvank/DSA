#include<bits/stdc++.h>
using namespace std;
int findMinEle(vector<int> &rota)
{
    int n = rota.size();
    int start = 0,end=n-1;
    int gstart = 0,gend=n-1;
    while(start<=end)
    {
        int mid = start+(end-start)/2;
        int prev = (mid-1+n)%n;
        int next = (mid+1)%n;
        if(rota[mid]<rota[prev]&&rota[mid]<rota[next])
            return mid;
        else if(rota[mid]>rota[gstart]&&rota[mid]>rota[gend])
            start=mid+1;
        else 
            end=mid-1;
    }
    return -1;
}
int binarySearch(vector<int> &rota,int start ,int end,int target)
{
    if(start>end)
        return -1;
    while(start<=end)
    {
        int mid = start+(end-start)/2;
        if(rota[mid]==target)
            return mid;
        else if(rota[mid]<target)
            start=mid+1;
        else
            end=mid-1;
    }
    return -1;
}
int findAnyElement(vector<int> &rota,int target)
{
    int n = rota.size();
    int minIndex=findMinEle(rota);
    int ans1 = binarySearch(rota,0,minIndex-1,target);
    int ans2 = binarySearch(rota,minIndex,n-1,target);
    if(ans1!=-1)
        return ans1;
    if(ans2!=-1)
        return ans2;
    return -1;
}
int main()
{
    vector<int> rota = {11,12,15,18,8};
    cout<<findAnyElement(rota,8)<<endl;
    return 0;
}