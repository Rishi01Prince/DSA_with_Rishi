#include <bits/stdc++.h>
using namespace std;

void solve()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int res = 0;
    int count=0;;
    for (int i = 1; i < n; i++)
    {
        if(((arr[i]%2==0)&&(arr[i-1]%2!=0))||((arr[i]%2!=0)&&(arr[i-1]%2==0))){
            count++;
            cout<<count<<"k"<<" ";
        }
        else{
            cout<<count<<" ";
           
            count=0;
        }
         res=max(count,res);
    }
    cout<<res+1<<endl;
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