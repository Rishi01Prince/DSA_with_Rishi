#include <bits/stdc++.h>
using namespace std;

//#define int long long int
// unordered_map<int,int> mpp;
// sort(v.begin(),v.end());


// void solve(vector<int> &v, int l, int h ,int n)
// {

//     if (l>h || l== n-1 || h==0){
//         return;
//     }

//     //swap
//     swap(v[l],v[h]);


//     solve(v,l+1,h-1,n);


// }

void solve(vector<int> &v,int i )
{

    if (i>=(v.size()/2)){
        return;
    }

    //swap
    swap(v[i],v[v.size()-1-i]);


    solve(v,i+1);


}



int32_t main()
{
    int T;
    cin >> T;

    while (T--)
    {

        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }

        solve(v , 0);

        for (int i = 0; i < n; i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}