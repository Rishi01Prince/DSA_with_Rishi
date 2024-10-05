#include <bits/stdc++.h>
using namespace std;

class Rishi_Stack
{

public:
    queue<int> q;
    queue<int> q2;

    int pop()
    {
        if (q.empty())
        {
            return -1;
        }
        q.pop();
    }

    int push(int x)
    {
       
        int l = q.size();
        for (int i = 0; i < l; i++)
        {
            q2.push(q.front());
            q.pop();

        }
        q.push(x);
        for (int i = 0; i < l; i++)
        {
            q.push(q2.front());
            q2.pop();
        }

    }

    
    int top()
    {
        if (q.empty())
        {
            return -1;
        }
        
        return q.front();
    }

    bool isempty()
    {
        return q.empty();
    }

    int size(){
        return q.size();
    }
};

int main()
{
    Rishi_Stack s;
    s.push(5);
    s.push(10);
    s.push(15);
    s.push(100);


    cout<<s.top()<<endl;

    s.pop();

     cout<<s.top()<<endl;




    return 0;
}