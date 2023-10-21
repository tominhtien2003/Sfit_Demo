#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int>adj[],vector<bool>vis){
    vis[node]=1;
    for (auto it:adj[node]){
        if (!vis[it]){
            dfs(it,adj,vis);
        }
    }
}
int main(){
    int vertex,edges;
    cin >> vertex >> edges;
    vector<int>adj[vertex];
    for (int i=0;i<edges;i++){
        int u,v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool>vis(vertex,0);
    dfs(0,adj,vis);
    return 0;
}