#include <bits/stdc++.h>
using namespace std;

class Rishi_Stack
{
public:
    int *arr;

    int data;
    int T_size;
    int top = -1;
    int top2 = -1;

    Rishi_Stack(int x)
    {
        arr = new int[x];
        T_size = x;
        top2 = T_size;
    }

    int push(int data)
    {
        top++;
        if (top == top2)
        {
            cout << " Sorry , Stack1 is Full : Overflow " << endl;
            top--;
            return -1;
        }
        
        arr[top] = data;

        return 1;
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "Sorry , No Elemnet Present in the Stack1  : Underflow " << endl;
            return -1;
        }
        top--;
        return arr[top + 1];
    }

    int seek()
    {
        if (top == -1)
        {
            cout << "Sorry , No Elemnet Present in the Stack1 " << endl;
            return -1;
        }
        cout << arr[top] << endl;
        return arr[top];
    }
    int size()
    {
        return top + 1;
    }

    // Stack 2

    int push2(int data)
    {
        top2--;

        if (top2 == top)
        {
            cout << " Sorry , Stack2 is Full : Overflow " << endl;
            top2++;
            return -1;
        }
        
        arr[top2] = data;

        return data;
    }

    int pop2()
    {
        if (top2 == T_size)
        {
            cout << "Sorry , No Elemnet Present in the Stack2  : Underflow " << endl;
            return -1;
        }

        top2++;
        return arr[top2 - 1];
    }

    int seek2()
    {
        if (top2 == T_size)
        {
            cout << "Sorry , No Elemnet Present in the Stack2  " << endl;
            return -1;
        }
        cout << arr[top2] << endl;
        return arr[top2];
    }
    int size2()
    {
        return (T_size - top2 );
    }

    void display()
    {

        cout << "Stack 1 is : " << endl;

        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << "  ";
        }
        cout << endl;
        cout << "Stack 2  is : " << endl;

        for (int i = top2;  i < T_size ; i++)
        {
            cout << arr[i] << "  ";
        }
        cout << endl;
    }
};

int main()
{
    int n;
    cout << "Please Enter the size of Array : ";
    cin >> n;

    Rishi_Stack s(n);
    cout << endl;

    bool u = true;
    cout << "                                               Functions are : " << endl;
    cout << "1.To Exit enter 'X' " << endl;
    cout << "2.To push in elemnet in stack1 enter 'p1' " << endl;
    cout << "3.To push in elemnet in stack2 enter 'p2' " << endl;
    cout << "4.To pop  elemnet from stack1 enter 'po1' " << endl;
    cout << "5.To pop elemnet from stack2 enter 'po2' " << endl;
    cout << "6.To seek stack1 top element enter 's1' " << endl;
    cout << "7.To seek stack2 top element enter 's2' " << endl;
    cout << "8.For size of Stack1 'l1' " << endl;
    cout << "9.For size of Stack2 'l2'  " << endl;
    cout << "10.To Display both stack enter 'D' " << endl;

    while (u)
    {
        string str;
        cout << "Please Enter Your Choice :  " << endl;
        cin >> str;

        if (str == "p1")
        {
            int data;
            cout<<"Enter Element : "<<endl;
            cin>>data;
            s.push(data);
        }
        else if (str == "p2")
        {
            int data;
            cout<<"Enter Element : "<<endl;
            cin>>data;
            s.push2(data);
        }
        else if (str == "po1")
        {
            s.pop();

        }
        else if (str == "po2")
        {
            s.pop2();
        }
        else if (str == "s1")
        {
            s.seek();
        }
        else if (str == "s2")
        {
             s.seek2();
        }
        else if (str == "l1")
        {
             cout<<s.size();
        }
        else if (str == "l2")
        {
             cout<<s.size2();
        }
        else if (str == "D")
        {
            s.display();
        }
        else if (str == "X")
        {
            u=false;
        }
        else{
            u=false;
        }
        cout<<endl;
    }

    return 0;
}