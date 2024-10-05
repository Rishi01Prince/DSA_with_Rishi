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

Node *Insertion_At_End_Tail(Node *tail, int data)
{
    if (tail == NULL)
    {
        return tail;
    }
    Node *temp = new Node(data);
    tail->f = temp;
    temp->b = tail;

    return temp;
}

// Without using tail Node

Node *Reverse(Node *head)
{
    if (head == NULL || head->f == NULL)
    {

        return head;
    }

    Node *curr = head;

    while (curr->f != NULL)
    {

        Node *temp = curr->f;
        curr->f = curr->b;
        curr->b = temp;
        curr = temp;
    }

    Node *new_head = curr;
    Node *temp = curr->f;
    curr->f = curr->b;
    curr->b = temp;

    return new_head;
}

void Traversal(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " -> ";
        curr = curr->f;
    }
    cout << "NULL" << endl;
}

int main()
{
    int n;
    cin >> n;

    Node *head = NULL;
    Node *tail = NULL;

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            int element;
            cin >> element;
            head = new Node(element);
            tail = head;
        }
        else
        {
            int element;
            cin >> element;
            tail = Insertion_At_End_Tail(tail, element);
        }
    }

    Traversal(head);
    head = Reverse(head);
    Traversal(head);

    return 0;
}