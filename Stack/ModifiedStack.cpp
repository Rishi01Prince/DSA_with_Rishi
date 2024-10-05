#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *f;
    Node *b;

    Node(int x)
    {
        data = x;
        f = NULL;
        b = NULL;
    }
};

class Doubly_Stack
{

public:
    int stack_size = 0;
    Node *midd = NULL;

    Node *push(int data, Node *tail)
    {
        if (head == NULL)
        {
            Node *first = new Node(data);
            head = first;
            tail = first;
            midd = first;
            stack_size = 1;
            return tail;
        }
        stack_size++;

        Node *temp = new Node(data);
        tail->f = temp;
        temp->b = tail;
        tail = tail->f;

        if (stack_size % 2 == 0)
        {
            midd = midd->f;
        }
        return tail;
    }
    Node *push_midd(Node *tail, int data)
    {

        if (head == NULL)
        {
            Node *first = new Node(data);
            head = first;
            tail = first;
            midd = first;
            stack_size = 1;
            return tail;
        }
        else if (s.stack_size == 1)
        {
            Node *temp = new Node(data);
            temp->f = tail;
            tail->b = temp;
            head = temp;
            stack_size = 2;
            return tail

        }
        else if (stack_size == 2)
        {
            Node *temp = new Node(data);
            temp->f = midd;
            midd->b = temp;
            head = temp;
            return tail;
        }

        Node *temp = new Node(data);
        hemp->f = midd;
        Node *saviour = midd->b;
        saviour->f = temp;
        midd->b = temp;
        temp->b = saviour;

        stack_size++;

        if (stack_size % 2 != 0)
        {
            midd = midd->b;
        }

        return tail;
    }

    Node *pop(Node *tail)
    {
        if (tail == NULL)
        {
            cout << -1 << endl;
            return NULL;
        }

        Node *temp = tail;
        tail = tail->b;
        tail->f = NULL;

        // Mid Changing
        stack_size--;
        if (stack_size == 0)
        {
            midd = NULL;
        }
        else if (stack_size == 1)
        {
            midd = midd->b;
        }
        if (stack_size % 2 == 0 && stack_size != 2)
        {
            midd = midd->f;
        }
        delete temp;
        return tail;
    }
    int mid()
    {
        if (midd == NULL)
        {

            return -1;
        }
        return midd->data;
    }

    Node *pop_mid(Node *tail)
    {
        if (midd == NULL)
        {
            cout << -1 << endl;
            return NULL;
        }
        else if (stack_size == 2)
        {
            Node *temp = midd;
            midd = midd->b;
            midd->f = NULL;
            stack_size--;
            delete temp;
            return midd;
        }

        Node *temp = midd->b;
        Node *temp2 = midd;
        temp->f = midd->f;
        midd->f->b = temp;

        stack_size--;

        if (stack_size % 2 == 0)
        {
            midd = midd->f;
        }
        else
        {
            midd = midd->b;
        }

        delete temp2;
        return tail;
    }

    int size()
    {
        return stack_size;
    }

    int seek(Node *tail)
    {
        if (tail == NULL)
        {
            return -1;
        }
        return tail->data;
    }

    void Traversal(Node *head)
    {

        Node *curr = head;
        cout << "NULL <- ";
        while (curr != NULL)
        {
            cout << curr->data << "  <->  ";
            curr = curr->f;
        }
        cout << " NULL ";
        cout << endl;
    }
};

int main()
{
    Doubly_Stack s;
    Node *head = NULL;
    Node *tail = NULL;

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int data;
        cin >> data;

        if (head == NULL)
        {
            Node *first = new Node(data);
            head = first;
            tail = first;
            s.midd = first;
            s.stack_size = 1;
        }
        else
        {
            tail = s.push(data, tail);
        }
    }

    int query;
    cin >> query;

    // 1. Push the element on the Stack.
    // 2. Insert an element in the middle in such a way so that the element moves away from top.
    // 3. Print the element at the top of stack.
    // 4. Print and remove the element from the middle.
    // 5. Print the middle element of stack.

    for (int i = 0; i < query; i++)
    {
        int p;
        cin >> p;

        if (p == 1)
        {

            int data;
            cin >> data;
            tail = s.push(data, tail);
        }
        else if (p == 2)
        {
            int data;
            cin >> data;

            
                tail = s.push_midd(tail, data);
            
        }

        else if (p == 3)
        {

            cout << s.seek(tail) << endl;
        }

        else if (p == 4)
        {
            cout << s.mid() << endl;

            if (s.stack_size == 1)
            {
                head = NULL;
                tail = NULL;
                s.midd = NULL;
                s.stack_size = 0;
            }
            else
            {
                tail = s.pop_mid(tail);
            }
        }
        else if (p == 5)
        {
            cout << s.mid() << endl;
        }
    }

    return 0;
}