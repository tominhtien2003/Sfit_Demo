#include<bits/stdc++.h>
using namespace std;

struct Edge {
  int u;
  int v;
};

bool dfs(vector<vector<Edge>> &graph, int u, int parent, vector<bool> &visited) {
  visited[u] = true;
  for (Edge edge : graph[u]) {
    if (!visited[edge.v]) {
      if (dfs(graph, edge.v, u, visited)) {
        return true;
      }
    } else if (edge.v != parent) {
      // Phát hiện chu kì
      return true;
    }
  }
  return false;
}

bool hasCycle(vector<vector<Edge>> &graph) {
  int n = graph.size();
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
  int n = 5;
  vector<vector<Edge>> graph(n);
  graph[0].push_back({1, 2});
  graph[1].push_back({0, 2});
  graph[2].push_back({0, 1});
  graph[3].push_back({2});

  if (hasCycle(graph)) {
    cout << "Đồ thị có chu kì" << endl;
  } else {
    cout << "Đồ thị không có chu kì" << endl;
  }

  return 0;
}