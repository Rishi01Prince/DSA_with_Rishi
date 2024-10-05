#include <bits/stdc++.h>
using namespace std;


void solve(){
    string str ;cin>>str;
    stack<int> s ;

    map <char,char> m; 
    m[']'] = '[';
    m['}'] = '{';
    m[')'] = '(';

    
    for (int i = 0; i < str.length(); i++)
    {
        if( i>0 && s.top()  == m[str[i]] ){
            s.pop();
        }
        else{
            s.push(str[i]);
        }
    }

    if(s.empty() == false ){
        cout<<"Not Balanced "<<endl;
    }
    else{
        cout<<"Balanced"<<endl;
    }

}

int main() {
    int T;
    cin>>T;

    while(T--){
        solve();
    }
    return 0;
}