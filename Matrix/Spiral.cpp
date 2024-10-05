#include <bits/stdc++.h>
using namespace std;

void solve2(vector<vector<int>> &arr)
{
    cout << "Hello ,................. Successful2" << endl;
    vector<int> temp;
    int rsize = arr.size();
    int csize = arr[0].size();
    int r = rsize;
    int c=csize ;
    

    //Outer element Printing with decrease in length
    for ( int k = 0; k < (rsize/2)+1; k++)
    {

        //For Row
        for (int i = k; i < rsize; i++)
        {
            if (i == k)
            {
                for (int j = k; j < (csize); j++)
                {

                    cout << arr[i][j] << " ";
                }
            }

            else if (i == rsize -1)
            {
                for (int j = csize - 1; j >= k; j--)
                {

                    cout << arr[i][j] << " ";
                }
            }
            else
            {
                temp.push_back(arr[i][k]);
                cout << arr[i][csize-1] << " ";
            }
        }
        if ((csize-k) > 1)
        {
            for (int i = temp.size()-1; i >= 0; i--)
            {
                cout << temp[i] <<"  ";
            }
        }
        temp.clear();
        rsize =rsize - 1;
        csize = csize -1;
       
    }
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> arr(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin>>arr[i][j];
        }
    }

    solve2(arr);
 
    return 0;
}