#include <bits/stdc++.h>
using namespace std;

void solve2(vector<vector<int>> &arr, int x)
{
    cout << "Hello ,................. Successful2" << endl;

    for (int j = arr[0].size() - 1; j > 0; j--)
    {

        if (arr[0][j] == x)
        {
            cout << 0 << " " << j;
            return;
        }
        
        else if (arr[0][j] < x)
        {
            for (int i = 0; i < arr.size(); i++)
            {
                if (arr[i][j] == x)
                {
                    cout << i << " " << j;
                    return;
                }
            }
        }
    }
    cout << "Not Found mm";
    return;
}

int main()
{

    vector<vector<int>> arr;
    int m;
    cin >> m;
    int n;
    cin >> n;

    for (int i = 0; i < m; i++)
    {
        vector<int> v;

        for (int j = 0; j < n; j++)
        {
            cin >> v.emplace_back(j);
        }
        arr.push_back(v);
    }
    int x;
    cin >> x;

    solve2(arr, x);

    return 0;
}