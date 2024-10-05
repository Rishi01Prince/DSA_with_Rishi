#include <bits/stdc++.h>
using namespace std;




//#define yes cout<<"Yes"<<endl;
// #define no cout<<"No"<<endl;
//#define int long long int
// map<int,int> mpp;
//sort(v.begin(),v.end());
//  A= 65   Z= 90  a =97  z = 122
//Int to string                 ostringstream str1; string str = str1.str();  str1 << num;
 //  String to Integer int num = stoi(str);


// Unique for vector
// vector<int>::iterator ip;ip = std::unique(v.begin(), v.end ());v.resize(std::distance(v.begin(), ip));
// Unique for string
// auto ip = unique(s.begin(), s.end());string un = string(s.begin(), ip);


//std::vector<int>::iterator upper1, upper2;
//upper1 = std::upper_bound(v.begin(), v.end(), 35);
//upper2 = std::upper_bound(v.begin(), v.end(), 45);
 //std::cout  << (upper1 - v.begin());
//std::cout << (upper2 - v.begin());


void solve(){


     int n ;
     cin>>n;
     vector<int> v(n);
     int zero = 0 ;
     int nega =0;
     int posi =0;
     long long int product = 1;
     int mi = INT_MAX;


     for (int i = 0; i < n; i++)
    { 
        cin>>v[i];

        if(v[i]==0){ zero++;}
        else{
            if(v[i]<0) {
                nega++;
                mi = min(mi , abs(v[i]));
            }
            else posi++;


            product*=abs(v[i]);
        }
    }

    

    if( zero==n || (zero== n-1 && nega == 1)){
        cout<<0<<endl;
    }
    else{
        if(nega%2  == 0){
            cout<<product<<endl;
        }
        else{
            product/=mi;

            cout<<product<<endl;

        }
    }






    



}

int32_t main() {
    int T;
    cin>>T;

    while(T--){
        solve();
    }
    return 0;
}