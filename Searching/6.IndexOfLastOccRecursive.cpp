#include <bits/stdc++.h>
using namespace std;

int BinaryRecSoln(vector<int> &v, int x, int l, int h)
{

    int mid = (l + h) / 2;

    if (l > h)
    {
        return -1;
    }

    if (x == v[mid])
    {
        
        // if(midv[mid]!=v[mid-1])
        if(mid==v.size()-1){
            return mid;
        }
        else if(v[mid]!=v[mid+1]){
            return mid;
        }
        else{
            return BinaryRecSoln(v, x, mid + 1, h);
        }

    }
    else if (x > v[mid])
    {
        return BinaryRecSoln(v, x, mid + 1, h);
    }
    else
    {
        return BinaryRecSoln(v, x, l, mid - 1);
    }
}

int main()
{
    int a;
    cin >> a;
    while (a--)
    {
        int n;
        cin >> n;

        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            cin >> v.emplace_back(i);
        }
        int x;
        cin >> x;
        int l = 0;
        int h = n - 1;

        int y = BinaryRecSoln(v, x, 0, h);
        if (y == -1)
        {
            cout << "Sorry Element not found " << endl;
        }
        else
        {
            cout << "The Last occurence is present at index : " << y << endl;
        }
    }

    return 0;
}