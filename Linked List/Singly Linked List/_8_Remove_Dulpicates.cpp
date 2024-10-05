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

void Remove_Duplicates(Node *dummy)
{
    if (dummy == NULL || dummy->p == NULL || dummy->p->p == NULL)
    {
        return;
    }

    Node *curr = dummy->p->p;
    dummy = dummy->p;

    while (curr != NULL)
    {
        if (curr->data == dummy->data)
        {
            Node *temp = dummy->p;
            curr = curr->p;
            dummy->p = curr;
            // dummy=curr;

            delete temp;
        }
        else
        {
            dummy = curr;
            curr = curr->p;
        }
    }
    return;
}

int main()

{
    int a;
    cin >> a;

    // Let us do using tail Pointer

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

    Remove_Duplicates(dummy);

    Traversal(head);
    return 0;
}
