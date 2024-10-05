#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    int ngrea[n];
    stack<int> st;

    st.push(n - 1);
    ngrea[n - 1] = -1;

    for (int i = 0; i < n; i++)
    {
       cin >> arr[i];
    }

    for (int i = n - 2; i >= 0; i--)
    {

        while ((st.empty() != 1) && (arr[st.top()] <= arr[i]))
        {
            st.pop(); 
        }


        if (st.empty())
        {
            ngrea[i] = -1;
            st.push(i);
        }
        else
        {
            ngrea[i] = arr[st.top()];
            st.push(i);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << ngrea[i] << " ";
    }
    cout << endl;
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