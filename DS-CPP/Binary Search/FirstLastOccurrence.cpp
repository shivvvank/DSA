#include<bits/stdc++.h>
using namespace std;
int firstOcc(vector<int> arr,int key)
{
    int start = 0,end = arr.size()-1,focc =INT_MAX;
    while(start<=end)
    {
        int mid =start +(end-start)/2;
        if(arr[mid]==key)
        {
            focc=mid+1;
            end=mid-1;
        }
        else if(arr[mid]>key)
            end = mid-1;
        else
            start = mid+1;
    }
    return focc;
}
int lastOcc(vector<int> arr,int key)
{
    int start =0,end=arr.size()-1,locc=INT_MIN;
    while(start<=end)
    {
        int mid = start+(end-start)/2;
        if(arr[mid]==key)
        {
            locc=mid+1;
            start = mid+1;
        }
        else if(arr[mid]>key)
            end = mid-1;
        else
            start = mid+1;
    }
    return locc;
}
int main()
{
    vector<int> arr= {1,2,3,4,4,4,4,5,5,6,7,8,9,10};
    cout<<lastOcc(arr,4)<<endl;
    return 0;
}