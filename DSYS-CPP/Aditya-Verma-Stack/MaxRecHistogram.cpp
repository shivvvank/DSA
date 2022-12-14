#include<bits/stdc++.h>
using namespace std;
int findmaxAreaRect(vector<int> m)
{
    vector<int> nextSMLeft,nextSMRight;
    stack<pair<int,int>> st;
    for(int i=0;i<m.size();i++)
    {
        while(st.size()>0&&st.top().first>=m[i])
            st.pop();
        if(st.size()==0)
        {
            nextSMLeft.push_back(i);
            st.push({m[i],i});
        }
        else
        {
            nextSMLeft.push_back(i-st.top().second-1);
            st.push({m[i],i});
        }
    }
    stack<pair<int,int>> st1;
    for(int i=m.size()-1;i>=0;i--)
    {
        while(st1.size()>0&&st1.top().first>=m[i])
            st1.pop();
        if(st1.size()==0)
        {
            nextSMRight.push_back(m.size()-i-1);
            st1.push({m[i],i});
        }
        else
        {
            nextSMRight.push_back(st1.top().second-i-1);
            st1.push({m[i],i});
        }
    }
    reverse(nextSMRight.begin(),nextSMRight.end());
    int maxi=-1;
    for(int i=0;i<m.size();i++)
    {
        int temp = (nextSMLeft[i]+nextSMRight[i]+1)*m[i];
        maxi=max(maxi,temp);
    }
    return maxi;
}
int maxAreaBHistogram(vector<vector<int>> arr)
{
    vector<vector<int>> mtemp;
    int n = arr.size();
    int m = arr[0].size();
    for(int i=0;i<n;i++)
    {
        vector<int> temp;
        for(int j=0;j<m;j++)
        {
            if(i==0)
            {
                temp.push_back(arr[i][j]);
            }
            else
            {
                if(arr[i][j]==1)
                {
                    temp.push_back(1+mtemp[i-1][j]);
                }
                else
                {
                    temp.push_back(0);
                }
            }
        }
        mtemp.push_back(temp);
    }
    for(int i = 0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<mtemp[i][j]<<" ";
        }
        cout<<endl;
    }
    int maxAreaRect = -1;
    for(int i = 0;i<n;i++)
    {
        maxAreaRect = max(maxAreaRect,findmaxAreaRect(mtemp[i]));
    }
    return maxAreaRect;
}
int main()
{
    vector<vector<int>> arr = {{0,1,1,0},{1,1,1,1},{1,1,1,1},{1,1,0,0}};
    cout<<maxAreaBHistogram(arr)<<endl;
    return 0;
}