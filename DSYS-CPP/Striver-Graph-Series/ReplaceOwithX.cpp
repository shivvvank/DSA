#include<bits/stdc++.h>
using namespace std;
void dfs(int n,int m,int start_i,int start_j,int delrow[],int delcol[],vector<vector<int>>& vis,vector<vector<char>> mat)
{
    vis[start_i][start_j]=1;
    for(int i=0;i<4;i++)
    {
        int nrow=start_i+delrow[i];
        int ncol=start_j+delcol[i];
        if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&mat[nrow][ncol]=='O'&&vis[nrow][ncol]==0)
        {
            dfs(n,m,nrow,ncol,delrow,delcol,vis,mat);
        }
    }
}
vector<vector<char>> ReplaceOwithX(int n,int m,vector<vector<char>> mat)
{
    vector<vector<char>> newmat(n,vector<char>(m,'O'));
    vector<vector<int>> vis(n,vector<int>(m,0));
    int delrow[]={-1,0,1,0};
    int delcol[]={0,1,0,-1};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if((i==0||i==n-1||j==0||j==m-1)&&mat[i][j]=='O')
            {
                dfs(n,m,i,j,delrow,delcol,vis,mat);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(vis[i][j]!=1)
            {
                newmat[i][j]='X';
            }
        }
    }
    return newmat;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>> mat(n,vector<char>(m,'O'));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>mat[i][j];
        }
    }
    vector<vector<char>> ans=ReplaceOwithX(n,m,mat);
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