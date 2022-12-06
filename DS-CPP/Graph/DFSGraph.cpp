#include<bits/stdc++.h>
using namespace std;
void DFS(int node, vector<int> adj[],int vis[],vector<int> &ls)
{
    vis[node]=1;
    ls.push_back(node);
    for(auto i: adj[node])
    {
        if(!vis[i])
        {
            DFS(i,adj,vis,ls);
        }
    }
}
// 1-index based 
vector<int> DFSofGraph(int V,vector<int> adj[])
{
    int vis[V+1];
    fill_n(vis,V+1,0);
    int start=1;
    vector<int> ls;
    DFS(start,adj,vis,ls);
    return ls;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=1;i<=m;i++)
    {
        int u,v;
        
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> bfs = DFSofGraph(9,adj);
    for(auto i:bfs)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}