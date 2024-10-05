#include <bits/stdc++.h>
using namespace std;
//Call by address
void solve(vector<vector<int>>* arr)
{
    cout << "Hello , Successful" << endl;

    for (int i = 0; i < (*arr).size(); i++)
    {
        for (int j = 0; j < (*arr)[i].size(); j++)
        {

            cout << (*arr)[i][j] << " ";
        }
        cout << endl;
    }
}
//Note here arr is a data type (of nested vector vector<vector<int>> ) not array
//Call by reference  
void solve2(vector<vector<int>> &arr)
{
    cout << "Hello ,................. Successful2" << endl;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {

            cout << arr[i][j] << " ";
        }
        cout << endl;
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
            cin>>v[j];
        }
        arr.push_back(v);
    }

    solve(&arr);
    solve2(arr);

    return 0;
}