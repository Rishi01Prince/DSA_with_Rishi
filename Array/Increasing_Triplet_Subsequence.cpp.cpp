#include <bits/stdc++.h>
using namespace std;

//#define int long long int
// unordered_map<int,int> mpp;
// sort(v.begin(),v.end());



bool solve(vector<int>& v){
    int a = INT_MAX;
    int b = INT_MAX;
    int c = INT_MAX;
    

    for (int i = 0; i < v.size(); i++)
    {
        if(v[i]<=a){
            a= v[i];
        }
        //greater than a 
        //check if greater than b or not
        else if(v[i]<=b){
            b=v[i];
        }
        //greater than b
        //check for greater than c or not
        else if(v[i]<c){
            c=v[i];

        }
    }
    // cout<<a<<" "<<b<<" "<<c<<endl;
    if((a!=INT_MAX) && (b!=INT_MAX)&&(c!=INT_MAX)){
        return true;
    }
    else{
        return false;
    }
    
    
    

}



  bool solve2(vector<int>& v){
    int a = INT_MAX;
    int b = INT_MAX;
    int c = INT_MAX;
    

    for (int i = 0; i < v.size(); i++)
    {
        if(v[i]<=a){
            a= v[i];
        }
        //greater than a 
        //check if greater than b or not
        else if(v[i]<=b){
            b=v[i];
        }
        //greater than b
        //check for greater than c or not
        else {
            return true;
            
        }

        
    }
  
        return false;

}

int32_t main()
{
    int T;
    cin >> T;
    

    while (T--)
    {

        string str;cin>>str; 
        vector<int> v;
        for (int i=0; i< str.length();i++)
        {
            if ((str[i] != ',') && (str[i] != '[') && (str[i] != ']')  ){
                v.push_back(int(str[i]-'0'));
            }   
        }
       
        cout<<solve(v)<<endl;
    }
    return 0;
}