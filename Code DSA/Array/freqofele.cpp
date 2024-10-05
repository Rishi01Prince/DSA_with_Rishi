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


    int count = 1;
    for (int i = 0; i < n; i++)
    {
        if(i>0 && i<n-1){
            if(arr[i]==arr[i-1]){
                count++;
            }
            else{
                cout<<arr[i-1]<<"  " << count<<endl;
                count = 1;
            }
        }
        
        else if(i==n-1){
            if(arr[i]==arr[i-1]){
                count++;
            }

            cout<<arr[n-1]<<" "<<count;
        }
    }
    
    cout<<endl;
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