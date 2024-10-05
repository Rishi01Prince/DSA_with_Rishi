#include <bits/stdc++.h>
using namespace std;

void solve2(vector<vector<int>> &arr)
{
    cout << "Hello ,................. Successful2" << endl;
    vector<int> temp;

    for (int i = 0; i < arr.size(); i++)
    {
        if (i == 0)
        {
            for (int j = 0; j < arr[i].size(); j++)
            {

                cout << arr[i][j] << " ";
            }
        }

        else if (i == arr.size() - 1)
        {
            for (int j = arr[i].size() - 1; j >= 0; j--)
            {

                cout << arr[i][j] << " ";
            }
        }
        else
        {
            temp.push_back(arr[i][0]);
            cout << arr[i][arr[i].size() - 1] << " ";
        }
    }

    if (arr[0].size() > 1)
    {
        for (int i = arr.size() - 3; i >= 0; i--)
        {
            cout << temp[i] << " ";
        }
    }
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
            int tr;
            cin >> tr;
            v.push_back(tr);
        }
        arr.push_back(v);
    }

    solve2(arr);

    return 0;
}