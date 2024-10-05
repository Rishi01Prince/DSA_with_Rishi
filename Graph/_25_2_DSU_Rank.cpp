#include <bits/stdc++.h>
using namespace std;
class DSU {
    vector<int> rank, parent;
public:
    DSU(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findpar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findpar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int par_u = findpar(u);
        int par_v = findpar(v);
        if (par_u == par_v) return;
        if (rank[par_u] < rank[par_v]) {
            parent[par_u] = par_v;
        }
        else if (rank[par_v] < rank[par_u]) {
            parent[par_v] = par_u;
        }
        else {
            parent[par_v] = par_u;
            rank[par_u]++;
        }
    }
};
int main() {
    DSU ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    
    if (ds.findpar(3) == ds.findpar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionByRank(3, 7);

    if (ds.findpar(3) == ds.findpar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;
}