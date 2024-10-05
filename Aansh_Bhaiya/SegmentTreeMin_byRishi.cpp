#include <bits/stdc++.h>
using namespace std;

class Segment_Tree
{
    vector<int> sgtree;

public:
    Segment_Tree(int n)
    {
        sgtree.resize(4 * n + 1);
    }

    void Build(vector<int> &v, int node, int low, int high)
    {

        if (low == high)
        {
            sgtree[node] = v[low];
            return;
        }

        int mid = (low + high) / 2;
        Build(v, 2 * node + 1, low, mid);
        Build(v, 2 * node + 2, mid + 1, high);
        sgtree[node] = min(sgtree[2 * node + 1], sgtree[2 * node + 2]);
    }

    int getmin(int node, int low, int high, int qs, int qe)
    {
        if (low > qe || high < qs)
            return INT_MAX;

        if (qs <= low && high <= qe)
            return sgtree[node];
        int mid = (low + high) / 2;

        int l = getmin(2 * node + 1, low, mid, qs, qe);
        int h = getmin(2 * node + 2, mid + 1, high, qs, qe);

        return min(l, h);
    }

    void update(int node, int low, int high, int ind , int val)
    {

        if (ind < low || ind > high || low>high) return;

        if(low == high){
            sgtree[node] = val ;
            return;
        }
        int mid = (low +high) /2 ;
      
        update(2*node+1 , low , mid , ind , val);
        update(2*node+2 , mid +1 , high , ind , val);

        sgtree[node] = min(sgtree[2*node+1] , sgtree[2*node+2]);
 
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
        cout << s.getmin(0, 0, n - 1, i, n - 1) << " ";
        
    }
    cout << endl;

    s.update(0 , 0 , n-1 , 1 , 10 );
     for (int i = 0; i < n; i++)
    {
        cout << s.getmin(0, 0, n - 1, i, n - 1) << " ";
        
    }
    cout << endl<<'\n';
    // cout<<s.getmin(0 , 0 , n -1 , 1 ,n-1)<<endl;
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