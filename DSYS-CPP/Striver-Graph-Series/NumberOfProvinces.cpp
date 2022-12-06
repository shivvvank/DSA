#include<bits/stdc++.h>
using namespace std;

void dfsHelper(int start,vector<int> adj[],int vis[])
{
    vis[start]=1;
    for(auto i:adj[start])
    {
        if(!vis[i])
            dfsHelper(i,adj,vis);
    }
}
int NumberOfProvinces(int V,vector<int> adj[])
{
    int vis[V+1];
    fill_n(vis,V+1,0);
    int count =0;
    for(int i=1;i<=V;i++)
    {
        if(!vis[i])
        {
            dfsHelper(i,adj,vis);
            count++;
        }
    }
    return count;
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
    cout<<NumberOfProvinces(n,adj)<<endl;
    return 0;
}