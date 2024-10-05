#include <bits/stdc++.h>
using namespace std;

//pass by address me array pass kr rahe ho to koi jarurat ni padti * deference operator
//use krne ki baar baar bas jaise normaly main me krte ho waise hi kro pr jb koi data type
//jaise ki int ya vector pass by (int* arr) hota hai andar har baar * operator use krna pdta hai
//agar koi value jaise ki int ya vector pass kr rahhe hai to kosish kare ki method ya function 
//me & se jise call by reference bolte hai use input le use baar baar deference ni krna parega jaise ki 
//int &a ya int vector int 

void solve(vector<int>* arr, int m)
{
    cout << "Hello , Successful" << endl;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {

            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// void solve2(vector<int> &arr, int m)
// {
//     cout << "Hello , Successful" << endl;

//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < arr[i].size(); j++)
//         {

//             cout << arr[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

int main()
{
    int m;
    cin >> m;
    vector<int> arr[m];
    int n;
    cin >> n;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp;
            cin >> temp;
            arr[i].push_back(temp);
        }
    }
    solve(arr,m);
    // solve2(arr,m)

    return 0;
}