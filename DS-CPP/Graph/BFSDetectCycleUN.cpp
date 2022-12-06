#include<bits/stdc++.h>
using namespace std;
bool DetectCycleBFS(int v,vector<int> adj[])
{
    int vis[v+1];
    fill_n(vis,v+1,0);
    queue<pair<int,int>> q;
    q.push({1,-1});
    vis[1]=1;
    while(!q.empty())
    {
        int node=q.front().first;
        int parentnode=q.front().second;
        q.pop();
        for(auto i:adj[node])
        {
            if(!vis[i])
            {
                vis[i]=1;
                q.push({i,node});
            }
            else
            {
                if(parentnode!=i)
                    return true;
            }
        }
    }
    return false;
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
    if(DetectCycleBFS(n,adj))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;
}