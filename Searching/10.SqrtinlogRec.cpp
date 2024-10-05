#include <bits/stdc++.h>
using namespace std;


//Here we are finding a last occourence of number or the greatest number wholse square is 
//less than equal to x

int SqrtRec(vector<int> &v, int x ,int l , int h , int ans)
{
    int mid = (l+h)/2;
    int sq = (v[mid]*v[mid]);

    if(l>h){
        return ans;
    }
    else if(sq>x){
        return SqrtRec(v,x,l,mid-1,ans);
    }
    //sq<x
    else{
        return SqrtRec(v,x,mid+1,h,mid);
    }
   
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

      
        int f = SqrtRec(v,T,0,T-1,-1);
       

        cout<<"Sqrt : "<<(f+1)<<endl;
       
    }

    return 0;
}