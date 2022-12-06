#include<bits/stdc++.h>
using namespace std;
int kthSmallest(int arr[],int n,int k)
{
    priority_queue<int> maxHeap;
    for(int i=0;i<n;i++)
    {
        maxHeap.push(arr[i]);
        if(maxHeap.size()>k)
            maxHeap.pop();
    }
    return maxHeap.top();
}
int main()
{
    int arr[] = {3,7,10,4,15};
    cout<<kthSmallest(arr,5,3)<<endl;
    return 0;
}