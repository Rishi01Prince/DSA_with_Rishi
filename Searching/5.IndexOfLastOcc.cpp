#include <bits/stdc++.h>
using namespace std;

// Iterative
int BinarySearch(vector<int> &v, int x)
{

    int l = 0;
    int h = v.size() - 1;
  
    while (l <= h)
    {
        int mid = (l + h) / 2;
        
        if (x > v[mid])
        {
            l = mid + 1;
        }
        else if (x < v[mid])
        {
            h = mid - 1;
        }
        else{
            if(mid == v.size()-1){
                return mid;
            }
            else if(v[mid+1]!=v[mid] ) {
                return mid;
            }
            else{
                
                l=mid+1;
                
            }
        }
        
        
        
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
            cin >> v.emplace_back(i);
        }
        int x;
        cin >> x;
        cout<<BinarySearch(v, x)<<endl;
       
    }

    return 0;
}