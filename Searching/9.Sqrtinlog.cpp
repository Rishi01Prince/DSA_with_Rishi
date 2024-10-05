#include <bits/stdc++.h>
using namespace std;


//Here we are finding a last occourence of number or the greatest number wholse square is 
//less than equal to x

int Sqrt(vector<int> &v, int x)
{

    int l = 0;
    int h = v.size() - 1;
    int ans = -1;
  
    while (l <= h)
    {
        int mid = (l + h) / 2;
        
        
        if ( x == (v[mid]*v[mid]))
        {
            return mid;
        }
        else if (x <(v[mid]*v[mid]))
        {
            h = mid - 1;
        }
        //x >(v[mid]*v[mid])
        else{
            l = mid+1;
            ans = mid;
           
        }
    }
    return ans;
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
        for (int i = 1; i <= T; i++)
        {
            v.push_back(i);
        }
        int f = Sqrt(v,T);
       

        cout<<"Sqrt : "<<(f+1)<<endl;
       
    }

    return 0;
}