#include <bits/stdc++.h>
using namespace std;

// Iterative
int LastOcc(vector<int> &v, int x)
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


int FirstOcc(vector<int> &v, int x)
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
            if(mid == 0){
                return mid;
            }
            else if(v[mid-1]!=v[mid] ) {
                return mid;
            }
            else{
                
                h=mid-1;
                
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
        int f = FirstOcc(v, x);
        int l = LastOcc(v,x);

        if(f==-1){
            cout<<"Element Not Present"<<endl;
        }
        else{
            cout<<"Occurence Count : "<<(l-f+1)<<endl;
        }
       
    }

    return 0;
}