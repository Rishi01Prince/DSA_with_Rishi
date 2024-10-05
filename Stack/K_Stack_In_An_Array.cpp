#include <bits/stdc++.h>
using namespace std;

class Rishi_Stack
{
public:
    int *arr;
    int *next;
    int *top;
    int *siz;
    int data;

    int freespot = 0;
    int T_size;
    int k;
    int check;

    Rishi_Stack(int n, int x)
    {
        arr = new int[n];
        next = new int[n];
        top = new int[x];
        siz = new int[x];
        T_size = n;
        k = x;
        check = k;

        for (int i = 0; i < n; i++)
        {
            if (i == n - 1)
            {
                next[i] = -1;
            }
            else
            {
                next[i] = i + 1;
            }
        }
        for (int i = 0; i < k; i++)
        {
            top[i] = -1;
        }
        for (int i = 0; i < k; i++)
        {
            siz[i] = 0;
        }
    }

    int push(int data, int k)
    {

        if (k > check)
        {
            cout << "Sorry , Only " << check << "   Stack are present" << endl;
            return -1;
        }

        if (freespot == -1)
        {
            cout << "Overflow" << endl;
            return -1;
        }

        int j = freespot;
        arr[j] = data;
        freespot = next[j];
        next[j] = top[k - 1];
        top[k - 1] = j;
        siz[k - 1] = siz[k - 1] + 1;
        return data;
    }

    int pop(int k)
    {

        if (top[k - 1] == -1)
        {
            cout << " Sorry , But No Elemenet Present In the Stack " << endl;
            return -1;
        }
        int j = top[k - 1];
        freespot = j;
        top[k - 1] = next[j];
        next[j] = freespot;
        siz[k - 1] = siz[k - 1] - 1;
        return arr[j];
    }

    int seek(int m)
    {
        if (m > k)
        {
            cout << "Sorry , Only " << k << " elements are present" << endl;
            return -1;
        }
        if (top[m - 1] == -1)
        {
            cout << "No Element Present In the Stack" << endl;
            return -1;
        }
        else
        {
            return top[m - 1];
        }
    }

    int size(int k)
    {
        return siz[k - 1];
    }

    void display()
    {
        cout << "Data : ";
        for (int i = 0; i < T_size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << endl;

        cout << "Next : ";
        for (int i = 0; i < T_size; i++)
        {
            cout << next[i] << " ";
        }
        cout << endl;
        cout << endl;

        cout << "Top : ";
        for (int i = 0; i < k; i++)
        {
            cout << top[i] << " ";
        }
        cout << endl;
        cout << endl;
    }
};

int main()
{
    int n, k;
    cout << "Please Enter the size of Array : ";
    cin >> n;
    cout << "Please Enter the no of Stack you want to make : ";
    cin >> k;

    Rishi_Stack s(n, k);
    cout << endl;
    if (n > 0 && n>=k)
    {

        bool u = true;

        cout << "                                   Functions are : " << endl;
        cout << "1.To Exit enter 'x' " << endl;
        cout << "2.To push in elemnet in stack enter 'u' " << endl;
        cout << "3.To pop elemnet from stack enter 'o' " << endl;
        cout << "4.For size of Stack 's' " << endl;
        cout << "5.To seek stack top element enter 't' " << endl;
        cout << "6.To Display Array 'd' " << endl;
        cout << "7.To Display all Functions enter 'f' " << endl;
        cout << endl;

        while (u)
        {
            string str;
            cout << "Please Enter Your Choice :  ";
            cin >> str;

            if (str == "u")
            {
                int data, stack_no;
                cout << "Enter Element : ";
                cin >> data;
                cout << endl;
                cout << "Enter Stack No : ";
                cin >> stack_no;
                cout << endl;
                s.push(data, stack_no);
            }
            else if (str == "o")
            {
                int stack_no;

                cout << "Enter Stack No : ";
                cin >> stack_no;
                cout << endl;
                s.pop(stack_no);
            }
            else if (str == "t")
            {
                int stack_no;

                cout << "Enter Stack No : ";
                cin >> stack_no;
                cout << endl;
                cout << s.seek(stack_no) << endl;
            }

            else if (str == "s")
            {
                int stack_no;
                cout << "Enter Stack No : ";
                cin >> stack_no;
                cout << endl;
                cout << "Size of Stack " << stack_no << "is : " << s.size(stack_no);
                cout << endl;
            }
            else if (str == "d")
            {
                s.display();
            }
            else if (str == "x")
            {
                u = false;
            }
            else if (str == "f")
            {
                cout << "                                               Functions are : " << endl;
                cout << "1.To Exit enter 'x' " << endl;
                cout << "2.To push in elemnet in stack enter 'u' " << endl;
                cout << "3.To pop elemnet from stack enter 'o' " << endl;
                cout << "4.For size of Stack 's' " << endl;
                cout << "5.To seek stack top element enter 't' " << endl;
                cout << "6.To Display Array 'd' " << endl;
                cout << "7.To Display all Functions enter 'f' " << endl;
            }
            else
            {
                cout << "Wrong Choice , Please Retry" << endl;
            }
            cout << endl;
        }
    }
    else{
        cout<<"The Given Input is Invalid"<<endl;
    }

    return 0;
}
