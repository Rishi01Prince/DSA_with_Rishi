#include <bits/stdc++.h>
using namespace std;







bool pali(string str , int i, string check){

    if(i>=(str.length()/2)){
        return (str == check) ? true : false;
    }
    swap(str[i], str[str.size()-1-i]);
    return pali(str,i+1,check);

}


bool striver(string str , int i){

    if(i>=(str.length()/2)){
        return true;
    }
    if(str[i] != str[str.size()-1-i] ) return false ;
    return striver(str,i+1);

}





int32_t main() {
    int T;
    cin>>T;

    while(T--){
        string str ; 
        cin>>str;
        cout<<pali(str,0,str)<<endl;
        cout<<striver(str,0)<<endl;
    }
    return 0;
}