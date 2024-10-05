#include <bits/stdc++.h>
using namespace std;

void solve()
{

    int n;
    cin >> n;
    int arr[n];
    int max = 0;
    int smax = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] > arr[max])
        {
            smax = max;
            max = i;
        }
        else if (smax == -1 || arr[i] > arr[smax])
        {
            smax = i;
        }
    }
    cout << "Max is : " << arr[max] << endl;
    cout << "Second Max is : " << arr[smax] << endl;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        solve();
    }
    return 0;
}