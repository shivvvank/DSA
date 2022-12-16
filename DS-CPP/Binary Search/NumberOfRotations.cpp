#include<bits/stdc++.h>
using namespace std;
int numOfRotation(vector<int> arr)
{
    int start = 0,end=arr.size()-1;
    int n = arr.size();
    while(start<=end)
    {
        int mid = start+(end-start)/2;
        int prev = (mid-1+n)%n;
        int next = (mid+1)%n;
        if(arr[mid]<arr[prev]&&arr[mid]<arr[next])
            return min(mid,abs(n-mid));
        else if(arr[mid]<arr[start]&&arr[mid]<arr[end])
            end = mid-1;
        else
            start=mid+1;
    }
    return 0;
}
int main()
{
    vector<int> arr={9,10,2,3,4,5,6,7,8};
    cout<<numOfRotation(arr)<<endl;
    return 0;
}
