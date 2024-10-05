#include <bits/stdc++.h>
using namespace std;

class Rishi_Stack
{

public:
    stack<int> s;
    int minn = INT_MAX;
    
    int _push(int data)
    {
        if (s.empty())
        {
            s.push(data);
            minn = data;
            return data;
        }
        else
        {
            int tp = s.top();
            if (data <= minn)
            {
                int res = data;
                s.push((2 * data) - minn);
                minn = data;
                return res;
            }
            else
            {
                s.push(data);
                return data;
            }
        }
    }

    int _pop()
    {
        if (s.empty())
        {
            cout << "Sorry , No Elemnet Present in the Array  : Underflow " << endl;
            return -1;
        }
        int tp = s.top();
        if (tp <= minn)
        {
            int res = minn;
            minn = (2 * minn) - tp;
            s.pop();
            return res;
        }
        else
        {
            s.pop();
            return tp;
        }
    }

    int _seek()
    {
        if (s.empty())
        {
            cout << "Sorry , No Elemnet Present in the Array  " << endl;
            return -1;
        }
        cout << s.top() << endl;
        return s.top();
    }
    int _size()
    {
        return s.size();
    }

    int _getmin()
    {
        return minn;
    }
};

int main()
{

    Rishi_Stack st;
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int a;
        cin >> a;
        st._push(a);
    }

    st._pop();

    cout << st._getmin() << endl;

    st._pop();
    st._pop();
    cout << st._getmin() << endl;

    return 0;
}