#include <bits/stdc++.h>
using namespace std;


void solve(){

    stack<int> st;
    stack<int> st2;
    st.push(5);
    st.push(3);
    st.push(2);
    st.push(1);
    st2 =st;


    for (int i = 0; i < 4; i++)
    {
       cout<<st2.top()<<" ";
       st2.pop();
    }
    cout<<endl;

    for (int i = 0; i < 4; i++)
    {
       cout<<st.top()<<" ";
       st.pop();
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