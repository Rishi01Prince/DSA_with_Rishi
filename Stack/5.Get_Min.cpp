#include <bits/stdc++.h>
using namespace std;

class Rishi_Stack
{
    int *arr;
    int data;
    int T_size;
    int top = -1;
    int minn = INT_MAX;

public:
 
    Rishi_Stack(int x)
    {
        arr = new int[x];
        T_size = x;
    }

    int push(int data)
    {
        if (top == T_size - 1)
        {
            cout << " Sorry , Stack is Full : Overflow " << endl;
            return -1;
        }

        if (top == -1)
        {
            top++;
            arr[top] = data;
            minn = arr[top];
            return arr[top];
        }
        else
        {
            int tp = arr[top];
            if (data <= minn)
            {
                top++;
                int res = data;
                arr[top] = (2 * data) - minn;
                minn = data;
                return res;
            }
            else
            {
                top++;
                arr[top] = data;
                return arr[top];
            }
        }
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "Sorry , No Elemnet Present in the Array  : Underflow " << endl;

            return -1;
        }
        int tp = arr[top];
        if (arr[top] <= minn)
        {
            int res = minn;
            minn = (2 * minn) - tp;
            top--;
            return res;
        }
        else
        {
            top--;
            return tp;
        }
    }

    int seek()
    {
        if (top == -1)
        {
            cout << "Sorry , No Elemnet Present in the Array  " << endl;
            return -1;
        }
        cout << arr[top] << endl;
        return arr[top];

    }

    int size()
    {
        return top + 1;
    }

    
    void display()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int getmin()
    {
        return minn;
    }
};

int main()
{

    Rishi_Stack s(10);
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int a;
        cin >> a;
        s.push(a);
    }

    s.pop();

    cout << s.getmin()<<endl;

    s.pop();
    s.pop();
    cout << s.getmin()<<endl;

    return 0;
}