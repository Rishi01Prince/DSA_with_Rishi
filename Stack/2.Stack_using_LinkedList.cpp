#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *p;

    Node(int x)
    {
        data = x;
        p = NULL;
    }
};

class Stack
{

public:
    int s = 0;
    Node *head = NULL;

    void traverse()
    {
        Node *curr = head;
        while (curr != NULL)
        {
            cout << curr->data << " ->  ";
            curr = curr->p;
        }
        cout << "  NULL " << endl;
    }

    void peek()
    {
        if (head == NULL)
        {
            cout << "No Element Present " << endl;
        }
        cout << head->data << endl;
    }

    // Insertion At Beginig
    void push(int data)
    {
        if (head == NULL)
        {
            head = new Node(data);
            s++;
        }
        else
        {
            Node *hemp = new Node(data);
            hemp->p = head;
            head = hemp;
            s++;
        }
    }

    void pop()
    {
        if (head == NULL)
        {
            cout << "Underflow : No elements Present " << endl;
        }
        Node *temp = head;
        head = head->p;
        delete temp;
        s--;
    }

    void size()
    {
        cout << s << endl;
    }
};

int main()
{
    // int n;
    // cin >> n;
    Stack s;
    s.push(10);
    s.push(8);
    s.push(6);
    s.push(4);
    s.traverse();
    cout << "Size : ";
    s.size();
    s.peek();
    s.pop();
    cout << "Size : ";
    s.size();
    s.peek();

    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.traverse();

    return 0;
}