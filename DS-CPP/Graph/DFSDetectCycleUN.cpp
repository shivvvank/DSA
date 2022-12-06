#include<bits/stdc++.h>
using namespace std;
bool DFSvisit(int node,int parent,vector<int> adj[],vector<int>& vis)
{
    vis[node]=1;
    for(auto i:adj[node])
    {
        if(!vis[i])
        {
            if(DFSvisit(i,node,adj,vis))
            {
                cout<<"node = "<<node<<" parent = "<<parent<<" i = "<<i<<endl;
                return true;
            }
        }
        else if(parent!=i&&parent !=-1)
        {
                cout<<"node = "<<node<<" parent = "<<parent<<" i = "<<i<<endl;

            return true;
        }
    }
    return false;
}
bool DetectCycleDFS(int v,vector<int> adj[])
{
    vector<int> vis(v+1,0);
    vis[1]=1;
    for(int i=1;i<=v;i++)
    {
        if(!vis[i])
        {
            if(DFSvisit(i,-1,adj,vis)==true) 
            {
                cout<<"node = "<<i<<endl;
                return true;
            }
        }
    }
    for(int i=0;i<v+1;i++)
    {
        cout<<vis[i]<<" ";
    }
    cout<<endl;
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
    if(DetectCycleDFS(n,adj))
        cout<<"Cycle Exist"<<endl;
    else
        cout<<"Doesn't exist"<<endl;
    return 0;
}