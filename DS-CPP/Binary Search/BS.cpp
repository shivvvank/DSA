#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> arr,int key)
{
    int low = 0;
    int high = arr.size()-1;
    while(low<=high)
    {
        int mid = low+(high-low)/2;
        if(arr[mid]==key)
            return mid+1;
        else if(arr[mid]>key)
            high=mid-1;
        else
            low=mid+1;
    }
    return -1;
}
int main()
{
    vector<int> arr = {1,2,3,4,5,6,7,8}; 
    cout<<binarySearch(arr,4)<<endl;
    return 0;
}