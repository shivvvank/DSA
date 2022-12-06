#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> FindClosest1(vector<vector<int>> matrix )
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans(n,vector<int>(m,INT_MAX));
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(matrix[i][j]==1)
            {
                q.push({i,j});
                ans[i][j]=0;
            }
        }
    }
    int delrow[]={-1,0,1,0};
    int delcol[]={0,1,0,-1};
    while(!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&(ans[row][col]>ans[nrow][ncol]+1))
            {
                ans[nrow][ncol]=min(ans[nrow][ncol],ans[row][col]+1);
                q.push({nrow,ncol});
            }
        }
    }
    return ans;
}
int main()
{
    int m,n;
    cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>matrix[i][j];
        }
    }
    vector<vector<int>> ans=FindClosest1(matrix);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}