#include<bits/stdc++.h>
using namespace std;
int vertex,edges;
bool dfs(vector<int> graph[], int u, int parent, vector<bool> &visited) {
  visited[u] = true;
  for (int it : graph[u]) {
    if (!visited[it]) {
      if (dfs(graph, it, u, visited)) {
        return true;
      }
    } else if (it != parent) {
      // Phát hiện chu kì
      return true;
    }
  }
  return false;
}

bool hasCycle(vector<int> graph[]) {
  int n = vertex;
  vector<bool> visited(n, false);
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      if (dfs(graph, i, -1, visited)) {
        return true;
      }
    }
  }
  return false;
}

int main() {
    
    cin >> vertex >> edges;
    vector<int>adj[vertex];
    for (int i=0;i<edges;i++){
        int u,v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

  if (hasCycle(adj)) {
    cout << "Đồ thị có chu kì" << endl;
  } else {
    cout << "Đồ thị không có chu kì" << endl;
  }

  return 0;
}