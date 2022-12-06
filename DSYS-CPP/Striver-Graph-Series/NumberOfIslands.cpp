#include<bits/stdc++.h>
using namespace std;
void BFS(int ro,int col,vector<vector<int>>& vis,vector<vector<int>> grid)
{
    int n=grid.size();
    int m=grid[0].size();
    vis[ro][col]=1;
    queue<pair<int,int>> q ;
    q.push({ro,col});
    while(!q.empty())
    {
        int row=q.front().first;
        int column =q.front().second;
        q.pop();
        for(int deltarow=-1;deltarow<=1;deltarow++)
        {
            for(int deltacol=-1;deltacol<=1;deltacol++)
            {
                int r=row+deltarow;
                int c=column+deltacol;
                if(r>=0&&r<n&&c>=0&&c<m&&grid[r][c]==1&&!vis[r][c])
                {
                    vis[r][c]=1;
                    q.push({r,c});
                }
            }
        }
    }

}
int NumberOfIslands(vector<vector<int>> grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!vis[i][j]&&grid[i][j]==1)
            {
                count++;
                BFS(i,j,vis,grid);
            }
        }
    }
    return count;
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
    cout<<NumberOfIslands(grid)<<endl;;
    return 0;
}