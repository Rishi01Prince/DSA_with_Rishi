#include <bits/stdc++.h>
using namespace std;




void solve()
{
    string str;
    cin >> str;
    int n = str.length();

    map<char, int> mpp;
    vector<char> ans(n, '5');
    int ma = INT_MIN;
    char max_fre = '0';

    for (int i = 0; i < str.length(); i++)
    {
        mpp[str[i]]++;

        if (ma < mpp[str[i]])
        {
            ma = mpp[str[i]];
            max_fre = str[i];
        }
    }

    if (ma > ((n + 1) / 2))
    {
        cout << -1 << endl;
        return;
    }

    int ind = 0;
    // T(freq of max element = ma)
    // For Even indexes Position

    while (ma && ind < n)
    {
    
        ans[ind] = max_fre;
        ind += 2;
        mpp[max_fre]--;
        ma--;
    }
    // can Also be used : ind = (ind >= N) ? 1 : ind;
    int odd = 1;
    for (auto it : mpp)
    {

        while (mpp[it.first] != 0 && ind < n)
        {
            ans[ind] = it.first;
            ind += 2;
            mpp[it.first]--;

        }

        while (mpp[it.first] != 0 && ind < n)
        {
            ans[ind] = it.first;
            ind += 2;
            mpp[it.first]--;
        }


        while (mpp[it.first] != 0 && odd < n)
        {
            ans[odd] = it.first;
            odd += 2;
            mpp[it.first]--;
        }
    }

    // my name is Rishi Raj
    // my nameis RajRishi   Rishiis



    for (int i = 0; i < n; i++)
    {
        cout << ans[i];
    }

    cout << endl;
}

int32_t main()
{
    int T;
    cin >> T;

    while (T--)
    {
        solve();
    }
    return 0;
}