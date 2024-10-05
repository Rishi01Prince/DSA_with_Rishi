#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *p;
    Node(int x)
    {
        data = x;
        p = NULL;
    }
};


void Traversal(Node *head)
{
    while (head != NULL)
    {
        cout << (head->data) << " -> ";
        head = (head->p);
    }
    cout << " NULL " << endl;
}
// Insertion at the End using tail Recursion O(1)

Node *insertion_at_End_tail(Node *tail, int element)
{

    Node *temp = new Node(element);
    tail->p = temp;

    return temp;
}

void Middle_Element(Node *head)
{
    bool x = false;
    if (head == NULL)
    {
        cout << "NULL" << endl;
        return;
    }
    if (head->p == NULL)
    {
        cout << head->data << endl;
        return;
    }
    Node *curr1 = head;
    Node *curr2 = head;
    while (curr1->p != NULL)
    {
        if ((curr1->p)->p != NULL)
        {
            x = true;
            break;
        }
        curr1 = curr1->p->p;
        curr2 = curr2->p;
    }

    if (x)
    {
        cout << (curr2->p)->data << endl;
    }
    else
    {
        cout << (curr2)->data << endl;
    }
    return;
}

int main()

{
    int a;
    cin >> a;

    Node *tail = NULL;
    Node *head = NULL;
    Node *dummy = new Node(-1);

    for (int i = 0; i < a; i++)
    {
        int element;
        cin >> element;
        if (i == 0)
        {
            head = new Node(element);
            dummy->p = head;
            tail = head;
        }
        else
        {
            tail = insertion_at_End_tail(tail, element);
        }
    }

    Traversal(head);
    Middle_Element(head);
    return 0;
}
