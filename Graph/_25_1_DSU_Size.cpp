#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent, size;
public:
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findpar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findpar(parent[node]);
    }
    
    void unionBySize(int u, int v) {
        int par_u = findpar(u);
        int par_v = findpar(v);
        if (par_u == par_v) return;
        if (size[par_u] < size[par_v]) {
            parent[par_u] = par_v;
            size[par_v] += size[par_u];
        }
        else {
            parent[par_v] = par_u;
            size[par_u] += size[par_v];
        }
    }
};
int main() {
    DSU ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    
    if (ds.findpar(3) == ds.findpar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionBySize(3, 7);

    if (ds.findpar(3) == ds.findpar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;
}