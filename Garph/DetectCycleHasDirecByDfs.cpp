#include<bits/stdc++.h>
using namespace std;

bool dfs(int node,vector<int>adj[],vector<bool>&vis,vector<bool>&pathVis){
    vis[node]=true;
    pathVis[node]=true;
    for (auto it:adj[node]){
        if (!vis[it]){
            if (dfs(it,adj,vis,pathVis)) return true;
        }
        else if (pathVis[it]) return true;
    }
    return false;
}
int main(){
    //do thi co huong
    int vertex,edges;
    cin >> vertex >> edges;
    vector<int>adj[vertex];
    for (int i=0;i<edges;i++){
        int u,v;cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<bool>vis(vertex,0),pathVis(vertex,0);
    for (int i=0;i<vertex;i++){
        if (!vis[i]){
            if (dfs(i,adj,vis,pathVis));
        }
    }
    return 0;
}