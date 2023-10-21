#include<bits/stdc++.h>
using namespace std;

int main(){
    int vertex,edges;
    cin >> vertex >> edges;
    vector<int>adj[vertex];
    for (int i=0;i<edges;i++){
        int u,v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int>Q;
    Q.push(0);
    vector<bool>vis(vertex,0);
    vis[0]=1;
    while (!Q.empty()){
        int node=Q.front();Q.pop();
        for (auto it : adj[node]){
            if (!vis[it]){
                vis[it]=1;
                Q.push(it);
            }
        }
    }
    return 0;
}