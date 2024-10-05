#include <bits/stdc++.h>
using namespace std;

bool pali(int num)
{
    int y = num;
    if (num / 10 <= 0)
    {
        return true;
    }

    int x = 0;

    while (num > 0)
    {

        x = x * 10 + (num % 10);
        num = num / 10;
    }
    if (x == y)
    {

        return true;
    }
    return false;
}

void solve()
{

    int n;
    vector<int> v;
    cin >> n;
    vector<int> v2(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        int z;
        cin >> z;
        v.push_back(z);
    }

    for (int i = 1; i <= n; i++)
    {
        v2[i] = v2[i - 1] + pali(v[i - 1]);
    }

    for (int i = 0; i <= n; i++)
    {
        cout << v2[i] << ' ';
    }
    cout << endl;

    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;

        cout << (v2[b] - v2[a - 1]) << endl;
    }
}

int main()
{
    int T = 1;
    // cin >> T;

    while (T--)
    {
        solve();
    }
    return 0;
}