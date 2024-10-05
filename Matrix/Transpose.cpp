#include <bits/stdc++.h>
using namespace std;

//Transpose for n*n

void solve2(vector<vector<int>> &arr)
{
    cout << "Hello ,................. Successful2" << endl;
    //arr.size() --->row
     //arr[i].size() --->coulmn

    for (int i = 0; i < arr.size(); i++)
    {

        for (int j = i+1; j < arr[i].size(); j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {

        for (int j = 0; j < arr[i].size(); j++)
        {

            cout << arr[i][j] << " ";
        }
        cout<<endl;
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