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

Node *Insertion_At_End(Node *head, int data)
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        
        return temp;
    }
    
    Node *temp = new Node(data);
    Node *curr = head;
    while (curr->f != NULL)
    {
        curr = curr->f;
    }

    curr->f = temp;
    temp->b = curr;

    return head;
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
            head = Insertion_At_End(head, element);
        }
    }

    Traversal(head);

    return 0;
}