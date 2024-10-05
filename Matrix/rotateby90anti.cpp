#include <bits/stdc++.h>
using namespace std;

//Transpose for n*n

void solve2(vector<vector<int>> &arr)
{
    

    for (int i = 0; i < arr.size(); i++)
    {

        for (int j = i+1; j < arr[i].size(); j++)
        {

            swap(arr[i][j], arr[j][i]);
        }
    }

    cout << "Hello ,................. Successful2" << endl;

    for (int i = 0; i < arr.size()/2; i++)
    {

        swap(arr[i],arr[arr.size()-1-i]);
    }



    cout<<arr.size()<<endl;

    for (int i = 0; i < arr.size(); i++)
    {

        for (int j = 0; j < arr[i].size(); j++)
        {
            
            cout << arr[i][j] << " ";
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;

    vector<vector<int>> arr( n  , vector<int> (m, 0));
   

    for (int i = 0; i < n; i++)
    {
        

        for (int j = 0; j < m; j++)
        {
            cin>>arr[i][j];
        }
      
    }

    solve2(arr);

    return 0;
}