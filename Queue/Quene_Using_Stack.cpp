#include <bits/stdc++.h>
using namespace std;


class Rishi_Quene{
    public:
    stack<int> st;
    stack<int> st2;

    int pop(){
        if(st2.empty() && st.empty()){
            return -1;
        }

        else if(st2.empty()){
            
            int l = st.size();
            for (int i = 0; i < l; i++)
            {
                st2.push(st.top());
                st.pop();
            }
            
        }
        st2.pop();
        return 1;

    }
    int push(int x){
        st.push(x);
    }
    int front(){
        if(st.empty()){
            return -1;
        }
        return  st.top();

    }
    int rear(){
        
    }
    int size(){

        return (st.size()+st2.size());

    }
    bool isempty(){
        return (st.empty()&&st2.empty());

    }

};

int main() {

    Rishi_Quene q;
    q.push(15);
    
    return 0;
}