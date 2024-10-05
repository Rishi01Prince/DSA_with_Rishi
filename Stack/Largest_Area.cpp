#include <bits/stdc++.h>
using namespace std;

void solve()
{

    int n;
    cin >> n;
    int arr[n];
    int nsmall[n];
    int psmall[n];
    int a = abs(3 - 4);
    stack<int> stn;
    stack<int> stp;

    nsmall[n - 1] = -1;
    psmall[0] = -1;
    stn.push(n - 1);
    stp.push(0);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Previous Small
    for (int i = 1; i < n; i++)
    {
        while ((stp.empty() != 1) && (arr[stp.top()] >= arr[i]))
        {
            stp.pop();
        }
        if (stp.empty())
        {
            psmall[i] = -1;
            stp.push(i);
        }
        else
        {
            psmall[i] = stp.top();
            stp.push(i);
        }
    }

    // Next Greater

    for (int i = n - 1; i >= 0; i--)
    {
        while ((stn.empty() != 1) && (arr[stn.top()] >= arr[i]))
        {
            stn.pop();
        }
        if (stn.empty())
        {
            nsmall[i] = -1;
            stn.push(i);
        }
        else
        {
            nsmall[i] = stn.top();
            stn.push(i);
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

    for (int i = 0; i < n; i++)
    {
        cout << nsmall[i] << " ";
    }
    cout << endl;

    int maxarea = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        if ((psmall[i] != -1) && (nsmall[i] != -1))
        {
            temp = (abs(psmall[i] - i)) + (abs(nsmall[i] - i)) - 1;
        }
        else if ((psmall[i] == -1) && (nsmall[i] != -1))
        {
            temp = (abs(nsmall[i] - i));
        }
        else if ((psmall[i] != -1) && (nsmall[i] == -1))
        {
            temp = (abs(psmall[i] - i));
        }
        maxarea = max(maxarea, (temp * arr[i]));
    }
    cout << maxarea << endl;
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