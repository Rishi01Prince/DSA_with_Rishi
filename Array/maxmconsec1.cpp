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
    
    int maxl =0;
    int temp=0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==1 ){
            temp++;
        }
        else{
            maxl = max(maxl,temp);
            temp = 0;
        }
        
    }
    if(temp>0){
        maxl = max(maxl,temp);
    }
    
    cout<<maxl<<endl;
    cout<<endl;


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