#include <bits/stdc++.h>
using namespace std;


void sub(string str , string pr,int i){
    if(i==str.length()){
        cout<<pr<<" ";
        return ;
    }

 //Two Branches each time either take a string or not take a string
    sub(str,pr+str[i],i+1);
    sub(str,pr,i+1);
}



int32_t main() {
    int T;
    cin>>T;

    while(T--){
        string str;cin>>str;
        sub(str,"",0);
    }
    return 0;
}



































