#include <bits/stdc++.h>
using namespace std;

void solve2(vector<vector<int>> &arr)
{
    cout << "Hello ,................. Successful2" << endl;

    for (int i = 0; i < arr.size(); i++)
    {
        if (i & 1)
        {
            for (int j = arr[i].size()-1 ; j >= 0; j--)
            {

                cout << arr[i][j] << " ";
            }
           
        }
        else
        {
            for (int j = 0; j < arr[i].size(); j++)
            {

                cout << arr[i][j] << " ";
            }
            
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
            cin >> v.emplace_back(j);
        }
        arr.push_back(v);
    }

   
    solve2(arr);

    return 0;
}