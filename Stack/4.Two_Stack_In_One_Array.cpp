#include <bits/stdc++.h>
using namespace std;


class Rishi_Stack{
    int *arr;

    int data;
    int T_size;
    int top = - 1;
    int minu = INT_MAX;
   

    public :

    Rishi_Stack (int x){
        arr = new int[x];
        T_size = x;
    }

    int push(int data){
        
        if(top == T_size-1){
            cout<< " Sorry , Stack is Full : Overflow " <<endl;
            return -1;
        }

        top++;
        arr[top] = data;

        return 1;
    }

    int pop(){
        if(top == -1){
            cout<< " Sorry , No Elemnet Present in the Array  : Underflow "<<endl;
            return -1;
        }
        top--;
        return 1;

    }

    int seek (){
         if(top == -1){
            cout<<"Sorry , No Elemnet Present in the Array  "<<endl;
            return -1;
        }
        cout<<arr[top]<<endl;
        return arr[top];

    }

    int size(){
        return top+1;
    }

    void display(){
        for (int i = 0; i <= top; i++)
        {
            cout<<arr[i]<<" " ;
        }
        cout<<endl;
    }

    int getmin(){
        return minu;

    }

};

int main() {

    Rishi_Stack s(5) ;

    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    s.push(10);

    s.seek();

    s.pop();
    s.seek();
    s.pop();
    s.seek();
    s.pop();
    s.seek();
    s.pop();
    s.seek();
    s.pop();
    s.pop();
   


  
   
    return 0;
}