#include <bits/stdc++.h>
using namespace std;

void AllPermutation(vector<int> v, vector<vector<int>>& ans, vector<int> ds, int ind)
{

    if (ind == v.size())
    {
        ans.push_back(v);
        return;
    }

    for (int i = ind; i < v.size(); i++)
    {

        swap(v[i], v[ind]);
        AllPermutation(v, ans, ds, ind + 1);
        swap(v[i], v[ind]);
    }
}

int32_t main()
{

    int n;
    cin >> n;
    vector<int> v(n);
    vector<vector<int>> ans;
    vector<int> ds;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    AllPermutation(v, ans, ds, 0);

    for (int i = 0; i < ans.size(); i++)
    {

        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}