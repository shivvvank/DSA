#include<bits/stdc++.h>
using namespace std;
void dfs(int n,int m,int sr,int sc ,int oldcolor,int newcolor,vector<vector<int>> grid,vector<vector<int>> &vis)
{
    vis[sr][sc]=newcolor;
    int delrow[] = {-1,0,1,0};
    int delcol[] ={0,1,0,-1};
    for(int i=0;i<4;i++)
    {
        int row = sr+delrow[i];
        int column = sc +delcol[i];
        if(row>=0&&row<n&&column>=0&&column<m&&grid[row][column]==oldcolor&&vis[row][column]!=newcolor)
        {
            dfs(n,m,row,column,oldcolor,newcolor,grid,vis);
        }
    }
}
vector<vector<int>> FloodFill(int sr,int sc,int oldcolor,int newcolor,vector<vector<int>> grid)
{
    int n = grid.size();
    int m=grid[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            vis[i][j]=grid[i][j];
        }
    }
    dfs(n,m,sr,sc,oldcolor,newcolor,grid,vis);
    return vis ;   
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int k;
            cin>>k;
            grid[i][j]=k;
        }
    }
    int sr,sc,oldcolor,newcolor;
    cin>>sr>>sc>>oldcolor>>newcolor;
    vector<vector<int>> vis=FloodFill(sr,sc,oldcolor,newcolor,grid);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<vis[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}