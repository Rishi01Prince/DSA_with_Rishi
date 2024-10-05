#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    int psmall[n];
    stack<int> st; 
    st.push(0);

    psmall[0] = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i < n; i++)
    {
        while ((st.empty() != 1) && (arr[st.top()] >= arr[i]))
        {
            st.pop();
        }


        if (st.empty())
        {
            psmall[i] = -1;
            st.push(i);
        }
        else
        {
            psmall[i] = arr[st.top()];
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
        cout << psmall[i] << " ";
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