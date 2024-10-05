#include <bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int> &v, int target)
{

    int n = v.size();
    int mi = INT_MAX;
    int ans = 0;

    sort(v.begin(), v.end());
    // cout<<"Hellob"<<endl;

    for (int i = 0; i < n; i++)
    {
        // cout<<"Hellosdf"<<endl;
        int l = i + 1;
        int h = n - 1;
        int x = v[i];
        // cout<<l<<" "<<h<<endl;

        while (l < h)
        {
            // cout<<"Hello0"<<endl;
            if ((x + v[l] + v[h]) == target)
            {
                return (x + v[l] + v[h]);
            }
            else if ((x + v[l] + v[h]) > target)
            {

                if (abs(target - (x + v[l] + v[h])) < mi)
                {
                    // cout<<"Hello1"<<endl;
                    ans = (x + v[l] + v[h]);
                    mi = abs(target - (x + v[l] + v[h]));
                }
                h--;
            }
            else
            {
                if (abs(target - (x + v[l] + v[h])) < mi)
                {
                    // cout<<"Hello2"<<endl;
                    ans = (x + v[l] + v[h]);
                    mi = abs(target - (x + v[l] + v[h]));
                }
                l++;
            }
        }
    }
    return ans;
}

int32_t main()
{
    int n, target;
    cin >> n >> target;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << threeSumClosest(v, target) << endl;
    return 0;
}