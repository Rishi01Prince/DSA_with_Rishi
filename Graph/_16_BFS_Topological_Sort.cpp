#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfs_topological_sort(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> in_degree(n, 0);
    for (int u = 0; u < n; u++) {
        for (int v : graph[u]) {
            in_degree[v]++;
        }
    }
    queue<int> q;
    for (int u = 0; u < n; u++) {
        if (in_degree[u] == 0) {
            q.push(u);
        }
    }
    vector<int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : graph[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }
    if (order.size() == n) {
        return order;
    } else {
        return {};
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    vector<int> order = bfs_topological_sort(graph);
    if (order.empty()) {
        cout << "The graph has a cycle\n";
    } else {
        cout << "Topological order:";
        for (int u : order) {
            cout << " " << u;
        }
        cout << "\n";
    }
    return 0;
}
