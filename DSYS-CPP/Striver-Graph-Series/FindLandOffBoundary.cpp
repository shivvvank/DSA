#include<bits/stdc++.h>
using namespace std;
void dfs(int n,int m,int starti,int startj,int delrow[],int delcol[],vector<vector<int>>& vis,vector<vector<int>> grid)
{   
    vis[starti][startj]=1;
    for(int i=0;i<4;i++)
    {
        int nrow=starti+delrow[i];
        int ncol=startj+delcol[i];
        if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&!vis[nrow][ncol]&&grid[nrow][ncol]==1)
        {
            dfs(n,m,nrow,ncol,delrow,delcol,vis,grid);
        }
    }
}
int CountWithoutBoundary(vector<vector<int>> grid)
{
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    int delrow[]={-1,0,1,0};
    int delcol[]={0,1,0,-1};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if((i==0||j==0||i==n-1||j==m-1)&&vis[i][j]==0&&grid[i][j]==1)
            {
                dfs(n,m,i,j,delrow,delcol,vis,grid);
            }
        }
    }
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(vis[i][j]!=1&&grid[i][j]==1)
            {
                count++;
            }
        }
    }
    return count;
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
    cout<<CountWithoutBoundary(matrix)<<endl;
    return 0;
}