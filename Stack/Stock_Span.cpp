#include <bits/stdc++.h>
using namespace std;

void solve()
{

    int n;
    cin >> n;
    int arr[n];
    int span[n];
    stack<int> st;
    st.push(0);
    span[0] = 1;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // cout << "Hello2" << endl;

    for (int i = 1; i < n; i++)
    {
        while ( (!st.empty())&&(arr[st.top()] <= arr[i])  )  //Anonymus Behaviour----> (arr[st.top()] <= arr[i])&&(!st.empty())
        {
            st.pop();
        }

        if (st.empty())
        {
            span[i] = i + 1;
            st.push(i);
        }
        else
        {
            span[i] = i - st.top() + 1;
            st.push(i);
        }
    }
    // cout<<"Hello3"<<endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << span[i] << " ";
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