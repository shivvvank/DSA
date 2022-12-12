#include<bits/stdc++.h>
using namespace std;
int revBinarySearch(vector<int> arr,int key)
{
    int start = 0;
    int end = arr.size()-1;
    while(start<=end)
    {
        int mid = start+(end-start)/2;
        if(arr[mid]==key)
            return mid+1;
        else if(arr[mid]>key)
            start = mid+1;
        else
            end = mid -1;
    }
    return -1;
}
int main()
{
    vector<int> arr={7,6,5,4,3,2,1};
    cout<<revBinarySearch(arr,3)<<endl;
    return 0;
}