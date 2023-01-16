#include<bits/stdc++.h>
using namespace std;
bool validPath(int n, vector<vector<int>>& edges, int s, int d) 
{
    vector<int> vis(n,0);
    vector<int> adj[n];
    for(int i=0;i<n;i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    stack<int> st;
    st.push(s);
    vis[s]=1;
    while(st.size()>0)
    {
        int temp = st.top();
        if(temp==d)
            return true;
        st.pop();
        for(auto i : adj[temp])
        {
            if(!vis[i])
                st.push(i),vis[i]=1;
        }
    }
    return false;
}
int main()
{
    vector<vector<int>> e = {{0,1},{1,2},{2,0}};
    cout<<validPath(3,e,0,2)<<endl;
    return 0;
}