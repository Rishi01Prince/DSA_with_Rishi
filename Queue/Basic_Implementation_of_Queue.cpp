#include <bits/stdc++.h>
using namespace std;

class Quen
{

public:
    int capacity;
    int *arr;
    int size = 0;

    Quen(int x)
    {
        capacity = x;
        arr = new int[x];
    }

    bool isEmpty()
    {
        return !size;
    }

    int lenght()
    {
        return size;
    }

    int enque(int data)
    {
        if (size == capacity)
        {
            cout << "Quene if Full" << endl;
            return -1;
        }
        

        arr[size] = data;
        size++;
        return data;
    }

    int deque()
    {

        if (size == 0)
        {
            cout << "Quene if Empty" << endl;
            return -1;
        }

        for (int i = 0; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
        return 1;
    }

    int rear()
    {
        if (size == 0)
        {
            return -1;
        }
        return arr[size - 1];
    }
    int front()
    {
        if (size == 0)
        {
            return -1;
        }

        return arr[0];
    }
};

int main()
{
    // int T;
    // cin >> T;

    Quen q(5);
    cout << q.isEmpty() << endl;
    q.enque(10);
    q.enque(9);
    q.enque(7);

    cout << q.isEmpty() << endl;
    cout << q.lenght() << endl;
    cout << q.front() << endl;

    q.deque();

    cout << q.isEmpty() << endl;
    cout << q.lenght() << endl;
    cout << q.front() << endl;

    q.enque(4);

    cout << q.isEmpty() << endl;
    cout << q.lenght() << endl;
    cout << q.front() << endl;

    q.enque(4);
    q.enque(4);
    q.enque(4);
    q.enque(4);

    q.deque();
    q.deque();
    q.deque();
    q.deque();
    q.deque();
    q.deque();
    q.deque();
    return 0;
}