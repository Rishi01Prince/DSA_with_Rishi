#include <bits/stdc++.h>
using namespace std;

// Iterative
int BinarySearch(vector<int> &v, int x)
{

    int l = 0;
    int h = v.size() - 1;
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
        for (int i = 0; i < T; i++)
        {   
            cin >> v[i];
        }
        int x;
        cin >> x;
        BinarySearch(v, x);
    }

    return 0;
}