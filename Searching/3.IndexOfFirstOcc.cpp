#include <bits/stdc++.h>
using namespace std;

// Iterative
int BinarySearch(vector<int> &v, int x)
{

    int l = 0;
    int h = v.size() - 1;
    int mid = (l + h) / 2;
    while (l <= h)
    {
        if (x > v[mid]){
            l = mid + 1;
        }
        else if (x < v[mid]){                                                                                                                                               
            h= mid-1; 
        }
        //x==v[mid]
        else
        {
            if(mid==0 || v[mid]!=v[mid-1]){
                return mid;
            }
            else{
                h = mid -1;
            }
            
        } 

        mid = (l + h) / 2;
    }
    return -1;
}

int main()
{
    int a;
    cin >> a;
    while (a--)
    {
        int T;
        cin >> T;

        vector<int> v;
        for (int i = 0; i < T; i++)
        {
            cin >> v[i];
        }
        int x;
        cin >> x;
        int ans = BinarySearch(v, x);

        if (ans == -1)
        {
            cout << "Element not Present " << endl;
        }
        else
        {
            int res = ans + 1;
            while (v[res] == v[ans])
            {
                res--;
            }
            res++;
            cout << "The first occurenc of element is at index " << res << endl;
        }
    }

    return 0;
}