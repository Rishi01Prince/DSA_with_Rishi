#include <bits/stdc++.h>
using namespace std;

void solve(int *arr[],int m, int n)
{
    cout << "Hello , Successful" << endl;

    for (int i = 0; i <m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int m;
    cin >> m;

    //  Array of Pointers
    int *arr[m];

    int n;
    cin >> n;

    for (int i = 0; i < m; i++)
    {
        arr[i] = new int[n];
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    solve(arr,m,n);

    return 0;
}