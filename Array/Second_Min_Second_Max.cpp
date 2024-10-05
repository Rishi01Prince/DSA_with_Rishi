#include <bits/stdc++.h>
using namespace std;

//min2 = Second Min
//max2 = Seond Max

void solve()
{

    int n;
    vector<int> v;
    cin >> n;
    int min = INT_MAX;
    int max = INT_MIN;
    int min2 =INT_MAX;
    int max2 = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int y;
        cin >>y;
        v.push_back(y);
     
        if(y<=min){
            min = y;
            
        }

        if (v[i] > max) {
            max2 = max;
            max = v[i];
        }
        else if (v[i] > max2 && v[i] != max2){
            max2 = v[i];
        }
    }
    if(max2 == INT_MIN){
        max2 = max;
    }

    for (int i = 0; i < n; i++)
    {
        if (v[i] < min2 && v[i] > min)
        {
            min2 = v[i];
        }


    }
    int c1 =0;
    int c2 =0;

    for (int i = 0; i < n; i++)
    {
        if (v[i] == min)
        {
            c1++;
        }
        if (v[i] == max)
        {
            c2++;
        }



    }
    if(c1>1){
        min2=min;
    }
    if(c2>1){
        max2=max;
    }
    // cout<<min<<" "<<max<<" "<<max2<<" "<<min2<<" "<<c1<<" "<<c2<<" ";
    
    if(max ==min || n==1){
        cout<<0<<endl;
    }
    else{
        long long int ans = (max - min ) + (max2-min2);
        cout<<ans<<endl;
    }
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