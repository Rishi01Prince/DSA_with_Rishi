#include <bits/stdc++.h>
using namespace std;

int BinarySearch(vector<int> &v, int x, int low, int high)
{

    int l = low;
    int h = high;
    int mid = (l + h) / 2;
    while (l <= h)
    {

        if (x == v[mid])
        {
            return mid;
        }
        else if (x > v[mid])
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
        mid = (l + h) / 2;
    }
    return -1;
}

int main()
{
    int a;
    cin >> a;

    while (a--)
    {

        int T;
        cin >> T;
        vector<int> v;

        for (int i = 1; i <= T; i++)
        {
            // int tr;
            // cin>>tr;
            v.push_back(i);
        }
        cout << "dfg";
        int x;
        cin >> x;
        int low = 0;
        int high = 0;

        if (v[0] == x)
        {
            cout << 0 << endl;
        }
        else
        {
            int j = 1;
            while (v[j] < x)
            {

                j = j * 2;
            }
        }

        if (v[j] == x)
        {
            cout << j << endl;
        }
        else
        {
            cout << BinarySearch(v, x, j / 2 + 1, j - 1) << endl;
        }
    }

    return 0;
}