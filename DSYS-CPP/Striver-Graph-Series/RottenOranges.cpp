#include<bits/stdc++.h>
using namespace std;
int MinTimeRot(vector<vector<int>> store)
{
    int n=store.size();
    int m=store[0].size();
    vector<vector<int>> temps=store;
    queue<pair<pair<int,int>,int>> q;
    int delrow[]={-1,0,1,0};
    int delcol[]={0,1,0,-1};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(store[i][j]==2)
            {
                q.push({{i,j},0});
            }
        }
    }
    int tmax=INT_MIN;
    while(!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int t = q.front().second;
        q.pop();
        tmax=max(t,tmax);
        for(int i=0;i<4;i++)
        {
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&temps[nrow][ncol]==1)
            {
                temps[nrow][ncol]=2;
                q.push({{nrow,ncol},t+1});
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(store[i][j]==1&&temps[i][j]!=2)
                return -1;
        }
    }
    return tmax;
}
int main()
{
    int m,n;
    cin>>n>>m;
    vector<vector<int>> store(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>store[i][j];
        }
    }
    cout<<MinTimeRot(store)<<endl;
    return 0;
}