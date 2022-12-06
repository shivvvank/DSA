#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//0-index based
vector<int> BFS(int n, vector<int> adj[])
{
    int vis[n];
    memset(vis,0,n*sizeof(int));
    vis[0]=1;
    queue<int> q;
    q.push(0);
    vector<int> bfs;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                vis[it]=1;
                q.push(it);
            }
        }
    }
    return bfs;
}
int main()
{
    int m,n;
    cin>>n>>m;
    vector<int> adj[n];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i:BFS(9,adj))
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}