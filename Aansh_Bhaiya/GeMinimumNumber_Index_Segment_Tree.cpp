#include <bits/stdc++.h>
using namespace std;

class Segment_Tree
{
    vector<pair<int, int>> sgtree;

public:
    Segment_Tree(int n)
    {
        sgtree.resize(4 * n + 1);
    }

    void Build(vector<int> &v, int node, int low, int high)
    {

        if (low == high)
        {
            // storing value;
            sgtree[node].first = v[low];
            // storing index;
            sgtree[node].second = low;
            return;
        }

        int mid = (low + high) / 2;
        Build(v, 2 * node + 1, low, mid);
        Build(v, 2 * node + 2, mid + 1, high);

        if (sgtree[2 * node + 1].first < sgtree[2 * node + 2].first)
        {
            sgtree[node] = sgtree[2 * node + 1];
        }
        else
        {
            sgtree[node] = sgtree[2 * node + 2];
        }
    }

    pair<int, int> getmin(int node, int low, int high, int qs, int qe)
    {
        if (low > qe || high < qs)
            return {INT_MAX, INT_MAX};

        if (qs <= low && high <= qe){
            return sgtree[node];
        }
            

        int mid = (low + high) / 2;

        pair<int, int> l = getmin(2 * node + 1, low, mid, qs, qe);
        pair<int, int> r = getmin(2 * node + 2, mid + 1, high, qs, qe);

        return l.first<r.first ? l :r;
    }

    void update(int node, int low, int high, int ind, int val)
    {

        if (ind < low || ind > high || low > high)
            return;

        if (low == high){
            sgtree[node].first = val;
            return;
        }
        int mid = (low + high) / 2;

        update(2 * node + 1, low, mid, ind, val);
        update(2 * node + 2, mid + 1, high, ind, val);

        if (sgtree[2 * node + 1].first < sgtree[2 * node + 2].first){
            sgtree[node] = sgtree[2 * node + 1];
        }
        else{
            sgtree[node] = sgtree[2 * node + 2];
        }
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    Segment_Tree s(n);
    s.Build(v, 0, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << s.getmin(0, 0, n - 1, i, n - 1).first << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << s.getmin(0, 0, n - 1, i, n - 1).second<< " ";
    }
    cout << endl<<'\n';


}

int32_t main()
{
    int T;
    cin >> T;

    while (T--)
    {
        solve();
    }
    return 0;
}